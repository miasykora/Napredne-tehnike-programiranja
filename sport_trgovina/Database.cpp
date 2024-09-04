#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include <iostream>

void kreirajTablice(sql::Connection* conn) {
    sql::Statement *stmt = conn->createStatement();

    // Kreiranje tablice Proizvodi
    stmt->execute("CREATE TABLE IF NOT EXISTS Proizvodi ("
                  "proizvod_id INT AUTO_INCREMENT PRIMARY KEY,"
                  "naziv VARCHAR(100),"
				  "cijena DECIMAL(10, 2),"
                  "kolicina INT,"
                  "slika LONGBLOB)");

    // Kreiranje tablice Kupci
    stmt->execute("CREATE TABLE IF NOT EXISTS Kupci ("
                  "kupac_id INT AUTO_INCREMENT PRIMARY KEY,"
                  "ime VARCHAR(100),"
                  "adresa VARCHAR(255))");

    // Kreiranje tablice Narudzbe
    stmt->execute("CREATE TABLE IF NOT EXISTS Narudzbe ("
                  "narudzba_id INT AUTO_INCREMENT PRIMARY KEY,"
                  "kupac_id INT,"
                  "proizvod_id INT,"
				  "kolicina INT,"
                  "ukupna_cijena DECIMAL(10, 2),"
                  "FOREIGN KEY (kupac_id) REFERENCES Kupci(kupac_id),"
                  "FOREIGN KEY (proizvod_id) REFERENCES Proizvodi(proizvod_id))");

    std::cout << "Tablice su uspješno kreirane ili veæ postoje." << std::endl;

    delete stmt;
}

void dodajProizvod(sql::Connection* conn, const std::string& naziv, double cijena, int kolicina, const std::string& filepath) {
    std::ifstream file(filepath, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Greška pri otvaranju datoteke: " << filepath << std::endl;
        return;
    }

    std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    sql::PreparedStatement *pstmt;
    pstmt = conn->prepareStatement("INSERT INTO Proizvodi(naziv, cijena, kolicina, slika) VALUES (?, ?, ?, ?)");

    pstmt->setString(1, naziv);
    pstmt->setDouble(2, cijena);
    pstmt->setInt(3, kolicina);
    pstmt->setBlob(4, &buffer[0], buffer.size());

    pstmt->executeUpdate();
    std::cout << "Proizvod " << naziv << " je dodan u bazu podataka." << std::endl;

    delete pstmt;
}

void prikaziProizvode(sql::Connection* conn) {
    sql::Statement *stmt;
    sql::ResultSet *res;

    stmt = conn->createStatement();
    res = stmt->executeQuery("SELECT * FROM Proizvodi");

    while (res->next()) {
        std::cout << "ID: " << res->getInt("proizvod_id")
                  << " | Naziv: " << res->getString("naziv")
                  << " | Cijena: " << res->getDouble("cijena")
                  << " | Kolièina: " << res->getInt("kolicina") << std::endl;
    }

    delete res;
    delete stmt;
}

void ucitajSlikuIzBaze(sql::Connection* conn, int proizvod_id, const std::string& output_path) {
    sql::PreparedStatement *pstmt;
    sql::ResultSet *res;

    pstmt = conn->prepareStatement("SELECT slika FROM Proizvodi WHERE proizvod_id = ?");
	pstmt->setInt(1, proizvod_id);

    res = pstmt->executeQuery();
    if (res->next()) {
        std::istream *blob = res->getBlob("slika");
        std::vector<char> buffer((std::istreambuf_iterator<char>(*blob)), std::istreambuf_iterator<char>());

        std::ofstream file(output_path, std::ios::binary);
        if (file.is_open()) {
            file.write(&buffer[0], buffer.size());
            file.close();
            std::cout << "Slika je uspješno uèitana iz baze podataka i spremljena kao " << output_path << std::endl;
        } else {
            std::cerr << "Greška pri otvaranju datoteke: " << output_path << std::endl;
        }
    }

    delete res;
    delete pstmt;
}


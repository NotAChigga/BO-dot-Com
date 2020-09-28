#include <iostream>
#include <stdlib.h>
#include <ctime> 
#include <iomanip>
using namespace std;

struct nameType {
	string first;
	string last;
};

struct baggageData {
	int weight;
};

struct seatNumber {
	int row;
	string column;
};

struct passengerData {
	string title;
	string idNumber;
	nameType name;
	string nationality;
	string phoneNumber;
	string email;
	int age;
	baggageData baggage;
	seatNumber seat;
	string ageGroup;
};

struct nowDate {
	int date;
	int month;
	int year;
};

void choosingSeat();

nowDate dateNow;

string nameCarrier[5] = {"Yaudah", "SitiLing", "MaungAir", "WaterAsia", "KotekaAir"};
double multiCarrier[5] = {1.3, 1.1, 0.75, 0.85, 0.9};

string nameClass[2] = {"Economy", "Business"};
double multiClass[2] = {1, 1.75};

double baseRoute[530] = {0};
string idPort[9] = {"CGK", "HLP", "BDO", "SOC", "SRG", "YIA", "JOG", "MLG", "SUB"};
string namePort[9] = {"Jakarta (CGK)", "Jakarta (HLP)", "Bandung (BDO)", "Solo (SOC)", "Semarang (SRG)", "Yogyakarta (YIA)", "Yogyakarta (YOG)", "Malang (MLG)", "Surabaya (SUB)"};
int indexPort[9] = {1, 2, 3, 5, 7, 11, 13, 17, 23};

double multiAge[3] = {1, 0.75, 0.5};

string timeInterval[4] = {"00.00 - 06.00", "06.00 - 12.00", "12.00 - 18.00", "18.00 - 00.00"};

string bank[4] = {"Mandi, Ri", "ABC", "BINI", "BRO"};

void bookingNum() {
	int r, q;
	char c;
	srand (time(NULL));
	for (int i = 0; i < 4; i++) {
		r = rand() % 26;
		c = 'A' + r;
		cout << c;
	}
		
	for (int j = 0; j < 2; j++) {
		q = (rand() % 9 + 1);
		cout << q;
	}
}

int book(int &numPassengers) {
	int fromAirport, toAirport; 
	int departDate, departMonth, departYear, returnDate, returnMonth, returnYear;
	int numAdult = 0, numChild = 0, numInfant = 0;
	int selectInterval;
	string roundTrip;
  
	cout << "Please choose the number correspond to your departure airport.";
	cout << endl;
	for (int i = 0; i < 9; i++){
    	cout << (i + 1) << ") " << namePort[i];
    	cout << endl;
	}
	cout << "From : ";
	cin >> fromAirport;
	cout << endl;
  
	cout << "Please choose the number correspond to your destination airport.";
    cout << endl;
    for (int i = 0; i < 9; i++){
        cout << (i + 1) << ") " << namePort[i];
        cout << endl;
    }
	cout << "To : ";
	cin >> toAirport;
	cout << endl; 
	system ("CLS");
	
	cout << "Input current date (DD MM YYYY): ";
	cin >> dateNow.date >> dateNow.month >> dateNow.year;
  
	if (roundTrip == "yes"){
		cout << "Departure date (DD MM YYYY): ";
		cin >> departDate >> departMonth >> departYear;	
		cout << "Return date (DD MM YYYY) : ";
		cin >> returnDate >> returnMonth >> returnYear;
	}
	else {
		cout << "Departure date (DD MM YYYY): ";
		cin >> departDate >> departMonth >> departYear;
	}
	cout << endl;
  
	cout << "Number of passengers : ";
	cout << endl;
	cout << "Adult (Age 12+) = ";
	cin >> numAdult;
	cout << endl; 
	cout << "Child (Age 2-11) = ";
	cin >> numChild;
	cout << endl;
	cout << "Infant (Age 0-2) = ";
	cin >> numInfant;
 
	numPassengers = numAdult + numChild + numInfant;
	cout << endl;
 
	system ("CLS");
 
	for (int i = 0; i < 4; i++){
		cout << (i + 1) << ") " << timeInterval[i];
        cout << endl;
	}
	cout << "Choose time interval : ";
	cin >> selectInterval;
 
	cout << "Please choose the number correspond to your desired seat class." << endl;
	for (int i = 0; i < 2; i++){
		cout << (i + 1) << ") " << nameClass[i];
		cout << endl;
	}
	int seatClass;
	cout << "Seat class : ";
	cin >> seatClass;
 
 
	int priceMulti = indexPort[fromAirport - 1] * indexPort[toAirport - 1];
	double basePrice = 0;
 
	if (priceMulti == 6 || priceMulti == 26){
    	basePrice = 500000;
	} 
	else if(priceMulti == 5 || priceMulti == 14 || priceMulti == 22 || priceMulti == 161) {
    	basePrice = 600000;
	}
	else if(priceMulti == 13 || priceMulti == 10 || priceMulti == 7) {
    	basePrice = 700000;
	}
    else if(priceMulti == 11 || priceMulti == 34 || priceMulti == 46 || priceMulti == 23 || priceMulti == 17) {
        basePrice = 1100000;
    }
    else if(priceMulti == 35 || priceMulti == 91 || priceMulti == 229) {
        basePrice = 1500000;
    }
    else if(priceMulti == 85 || priceMulti == 115 || priceMulti == 119 || priceMulti == 65) {
      basePrice = 1800000;
	}
    else if(priceMulti == 69 || priceMulti == 221) {
        basePrice = 2000000;
	}
    else if(priceMulti == 391) {
       basePrice = 2300000;
	}
	
	double price1 = basePrice * multiClass[seatClass - 1];
	
	int price1_year = (departYear - dateNow.year);
	int price1_month = (departMonth - dateNow.month);
	int price1_date = (departDate - dateNow.date);
	
	int price_difference = (price1_year + price1_month + price1_date);
	
	if (price_difference <= 3) {
		price1 *= 1.7;
	}
	else if (price_difference <= 7) {
		price1 *= 1.5;
	}
	else if (price_difference <= 14) {
		price1 *= 1.3;
	}
	else if (price_difference <= 30) {
		price1 *= 1.1;
	}
	else if (price_difference <= 60) {
		price1 *= 1;
	}
	else if (price_difference <= 90) {
		price1 *= 0.8;
	}
	else if (price_difference <= 180) {
		price1 *= 0.7;
	}
	else {
		price1 *= 0.5;
	}

	int priceArray[4];
	int flightChoice;

	const int n = 5;
	int random[5];
	srand((unsigned)time(NULL));
	for (int i = 0; i < 5; i++) {
		random[i] = (rand() % 5);
	}

	cout << setw(15) << "Time" << setw(15) << "Airplane" << setw(30) << "Price/pax (IDR)" << endl;
	
	int timeMulti = priceMulti;
	
	int price2[5];
	
	if (timeMulti == 6){
		if (selectInterval == 1) {
			string time[5] = {"00.30 - 01.15", "01.45 - 02.30", "03.00 - 03.45", "04.30 - 05.15", "05.00 - 05.45"};

			for (int i = 0; i < 5; i++) {
    			nameCarrier[random[i]];
    		}
    		
    		for (int j = 0; j < 5; j++) {
				if (nameCarrier[random[j]] == "Yaudah") {
					price2[j] = price1 * multiCarrier[0];
				}
				if (nameCarrier[random[j]] == "SitiLing") {
					price2[j] = price1 * multiCarrier[1];
				}
				if (nameCarrier[random[j]] == "MaungAir") {
					price2[j] = price1 * multiCarrier[2];
				}
				if (nameCarrier[random[j]] == "WaterAsia") {
					price2[j] = price1 * multiCarrier[3];
				}
				if (nameCarrier[random[j]] == "KotekaAir") {
					price2[j] = price1 * multiCarrier[4];
				}
    		}
    		
    		for (int i = 0; i < 5; i++) {
    			cout << (i + 1) << ") " << time[i] << setw(15) << nameCarrier[random[i]] << setw(30) << price2[i] << endl;
    		}
		}
 	
		if (selectInterval == 2) {
			string time[5] = {"06.30 - 07.15", "07.45 - 08.30", "09.00 - 09.45", "10.30 - 11.15", "11.00 - 11.45"};
			
			for (int i = 0; i < 5; i++) {
    			nameCarrier[random[i]];
    		}
    		
    		for (int j = 0; j < 5; j++) {
				if (nameCarrier[random[j]] == "Yaudah") {
					price2[j] = price1 * multiCarrier[0];
				}
				if (nameCarrier[random[j]] == "SitiLing") {
					price2[j] = price1 * multiCarrier[1];
				}
				if (nameCarrier[random[j]] == "MaungAir") {
					price2[j] = price1 * multiCarrier[2];
				}
				if (nameCarrier[random[j]] == "WaterAsia") {
					price2[j] = price1 * multiCarrier[3];
				}
				if (nameCarrier[random[j]] == "KotekaAir") {
					price2[j] = price1 * multiCarrier[4];
				}
    		}
    		
    		for (int i = 0; i < 5; i++) {
    			cout << (i + 1) << ") " << time[i] << setw(15) << nameCarrier[random[i]] << setw(30) << price2[i] << endl;
    		}
		}
		
 		if (selectInterval == 3) {
			string time[5] = {"12.30 - 13.15", "13.45 - 14.30", "15.00 - 15.45", "16.30 - 17.15", "17.00 - 17.45"};
		
			for (int i = 0; i < 5; i++) {
    			nameCarrier[random[i]];
    		}
    		
    		for (int j = 0; j < 5; j++) {
				if (nameCarrier[random[j]] == "Yaudah") {
					price2[j] = price1 * multiCarrier[0];
				}
				if (nameCarrier[random[j]] == "SitiLing") {
					price2[j] = price1 * multiCarrier[1];
				}
				if (nameCarrier[random[j]] == "MaungAir") {
					price2[j] = price1 * multiCarrier[2];
				}
				if (nameCarrier[random[j]] == "WaterAsia") {
					price2[j] = price1 * multiCarrier[3];
				}
				if (nameCarrier[random[j]] == "KotekaAir") {
					price2[j] = price1 * multiCarrier[4];
				}
    		}
    		
    		for (int i = 0; i < 5; i++) {
    			cout << (i + 1) << ") " << time[i] << setw(15) << nameCarrier[random[i]] << setw(30) << price2[i] << endl;
    		}
 		}
 		
		if (selectInterval == 4){
			string time[5] = {"18.30 - 19.15", "19.45 - 20.30", "21.00 - 21.45", "22.30 - 23.15", "23.00 - 23.45"};

			for (int i = 0; i < 5; i++) {
    			nameCarrier[random[i]];
    		}
    		
    		for (int j = 0; j < 5; j++) {
				if (nameCarrier[random[j]] == "Yaudah") {
					price2[j] = price1 * multiCarrier[0];
				}
				if (nameCarrier[random[j]] == "SitiLing") {
					price2[j] = price1 * multiCarrier[1];
				}
				if (nameCarrier[random[j]] == "MaungAir") {
					price2[j] = price1 * multiCarrier[2];
				}
				if (nameCarrier[random[j]] == "WaterAsia") {
					price2[j] = price1 * multiCarrier[3];
				}
				if (nameCarrier[random[j]] == "KotekaAir") {
					price2[j] = price1 * multiCarrier[4];
				}
    		}
    		
    		for (int i = 0; i < 5; i++) {
    			cout << (i + 1) << ") " << time[i] << setw(15) << nameCarrier[random[i]] << setw(30) << price2[i] << endl;
    		}
    	}
	}
 	
	if (timeMulti == 35 || timeMulti == 65 || timeMulti == 85 || timeMulti == 91 || timeMulti == 119 || timeMulti == 221) {
		if (selectInterval == 1) {
			string time[5] = {"00.30 - 01.30", "01.45 - 02.45", "03.00 - 04.00", "04.30 - 05.30", "05.00 - 06.00"};

			for (int i = 0; i < 5; i++) {
    			nameCarrier[random[i]];
    		}
    		
    		for (int j = 0; j < 5; j++) {
				if (nameCarrier[random[j]] == "Yaudah") {
					price2[j] = price1 * multiCarrier[0];
				}
				if (nameCarrier[random[j]] == "SitiLing") {
					price2[j] = price1 * multiCarrier[1];
				}
				if (nameCarrier[random[j]] == "MaungAir") {
					price2[j] = price1 * multiCarrier[2];
				}
				if (nameCarrier[random[j]] == "WaterAsia") {
					price2[j] = price1 * multiCarrier[3];
				}
				if (nameCarrier[random[j]] == "KotekaAir") {
					price2[j] = price1 * multiCarrier[4];
				}
    		}
    		
    		for (int i = 0; i < 5; i++) {
    			cout << (i + 1) << ") " << time[i] << setw(15) << nameCarrier[random[i]] << setw(30) << price2[i] << endl;
    		}
		}
		
		if (selectInterval == 2) {
			string time[5] = {"06.30 - 07.30", "07.45 - 08.45", "09.00 - 10.00", "10.30 - 11.30", "11.00 - 12.00"};

			for (int i = 0; i < 5; i++) {
    			nameCarrier[random[i]];
    		}
    		
    		for (int j = 0; j < 5; j++) {
				if (nameCarrier[random[j]] == "Yaudah") {
					price2[j] = price1 * multiCarrier[0];
				}
				if (nameCarrier[random[j]] == "SitiLing") {
					price2[j] = price1 * multiCarrier[1];
				}
				if (nameCarrier[random[j]] == "MaungAir") {
					price2[j] = price1 * multiCarrier[2];
				}
				if (nameCarrier[random[j]] == "WaterAsia") {
					price2[j] = price1 * multiCarrier[3];
				}
				if (nameCarrier[random[j]] == "KotekaAir") {
					price2[j] = price1 * multiCarrier[4];
				}
    		}
    		
    		for (int i = 0; i < 5; i++) {
    			cout << (i + 1) << ") " << time[i] << setw(15) << nameCarrier[random[i]] << setw(30) << price2[i] << endl;
    		}
		}
		
		if (selectInterval == 3){
			string time[5] = {"12.30 - 13.30", "13.45 - 14.45", "15.00 - 16.00", "16.30 - 17.30", "17.00 - 18.00"};

			for (int i = 0; i < 5; i++) {
    			nameCarrier[random[i]];
    		}
    		
    		for (int j = 0; j < 5; j++) {
				if (nameCarrier[random[j]] == "Yaudah") {
					price2[j] = price1 * multiCarrier[0];
				}
				if (nameCarrier[random[j]] == "SitiLing") {
					price2[j] = price1 * multiCarrier[1];
				}
				if (nameCarrier[random[j]] == "MaungAir") {
					price2[j] = price1 * multiCarrier[2];
				}
				if (nameCarrier[random[j]] == "WaterAsia") {
					price2[j] = price1 * multiCarrier[3];
				}
				if (nameCarrier[random[j]] == "KotekaAir") {
					price2[j] = price1 * multiCarrier[4];
				}
    		}
    		
    		for (int i = 0; i < 5; i++) {
    			cout << (i + 1) << ") " << time[i] << setw(15) << nameCarrier[random[i]] << setw(30) << price2[i] << endl;
    		}
		}
		if (selectInterval == 4) {
			string time[5] = {"18.30 - 19.30", "19.45 - 20.45", "21.00 - 22.00", "22.30 - 23.30", "23.00 - 00.00"};

			for (int i = 0; i < 5; i++) {
    			nameCarrier[random[i]];
    		}
    		
    		for (int j = 0; j < 5; j++) {
				if (nameCarrier[random[j]] == "Yaudah") {
					price2[j] = price1 * multiCarrier[0];
				}
				if (nameCarrier[random[j]] == "SitiLing") {
					price2[j] = price1 * multiCarrier[1];
				}
				if (nameCarrier[random[j]] == "MaungAir") {
					price2[j] = price1 * multiCarrier[2];
				}
				if (nameCarrier[random[j]] == "WaterAsia") {
					price2[j] = price1 * multiCarrier[3];
				}
				if (nameCarrier[random[j]] == "KotekaAir") {
					price2[j] = price1 * multiCarrier[4];
				}
    		}
    		
    		for (int i = 0; i < 5; i++) {
    			cout << (i + 1) << ") " << time[i] << setw(15) << nameCarrier[random[i]] << setw(30) << price2[i] << endl;
    		}
		}
	}
	
	if (timeMulti == 7 || timeMulti == 14 || timeMulti == 22 || timeMulti == 26 || timeMulti == 115 || timeMulti == 161 || timeMulti == 391){
		if (selectInterval == 1){
			string time[5] = {"00.30 - 01.40", "01.45 - 02.55", "03.00 - 04.10", "04.30 - 05.40", "05.00 - 06.10"};

			for (int i = 0; i < 5; i++) {
    			nameCarrier[random[i]];
    		}
    		
    		for (int j = 0; j < 5; j++) {
				if (nameCarrier[random[j]] == "Yaudah") {
					price2[j] = price1 * multiCarrier[0];
				}
				if (nameCarrier[random[j]] == "SitiLing") {
					price2[j] = price1 * multiCarrier[1];
				}
				if (nameCarrier[random[j]] == "MaungAir") {
					price2[j] = price1 * multiCarrier[2];
				}
				if (nameCarrier[random[j]] == "WaterAsia") {
					price2[j] = price1 * multiCarrier[3];
				}
				if (nameCarrier[random[j]] == "KotekaAir") {
					price2[j] = price1 * multiCarrier[4];
				}
    		}
    		
    		for (int i = 0; i < 5; i++) {
    			cout << (i + 1) << ") " << time[i] << setw(15) << nameCarrier[random[i]] << setw(30) << price2[i] << endl;
    		}
		}
		
		if (selectInterval == 2){
			string time[5] = {"06.30 - 07.40", "07.45 - 08.55", "09.00 - 10.10", "10.30 - 11.40", "11.00 - 12.10"};
	
			for (int i = 0; i < 5; i++) {
    			nameCarrier[random[i]];
    		}
    		
    		for (int j = 0; j < 5; j++) {
				if (nameCarrier[random[j]] == "Yaudah") {
					price2[j] = price1 * multiCarrier[0];
				}
				if (nameCarrier[random[j]] == "SitiLing") {
					price2[j] = price1 * multiCarrier[1];
				}
				if (nameCarrier[random[j]] == "MaungAir") {
					price2[j] = price1 * multiCarrier[2];
				}
				if (nameCarrier[random[j]] == "WaterAsia") {
					price2[j] = price1 * multiCarrier[3];
				}
				if (nameCarrier[random[j]] == "KotekaAir") {
					price2[j] = price1 * multiCarrier[4];
				}
    		}
    		
    		for (int i = 0; i < 5; i++) {
    			cout << (i + 1) << ") " << time[i] << setw(15) << nameCarrier[random[i]] << setw(30) << price2[i] << endl;
    		}
  		}
  		
		if (selectInterval == 3) {
			string time[5] = {"12.30 - 13.40", "13.45 - 14.55", "15.00 - 16.10", "16.30 - 17.40", "17.00 - 18.10"};

			for (int i = 0; i < 5; i++) {
    			nameCarrier[random[i]];
    		}
    		
    		for (int j = 0; j < 5; j++) {
				if (nameCarrier[random[j]] == "Yaudah") {
					price2[j] = price1 * multiCarrier[0];
				}
				if (nameCarrier[random[j]] == "SitiLing") {
					price2[j] = price1 * multiCarrier[1];
				}
				if (nameCarrier[random[j]] == "MaungAir") {
					price2[j] = price1 * multiCarrier[2];
				}
				if (nameCarrier[random[j]] == "WaterAsia") {
					price2[j] = price1 * multiCarrier[3];
				}
				if (nameCarrier[random[j]] == "KotekaAir") {
					price2[j] = price1 * multiCarrier[4];
				}
    		}
    		
    		for (int i = 0; i < 5; i++) {
    			cout << (i + 1) << ") " << time[i] << setw(15) << nameCarrier[random[i]] << setw(30) << price2[i] << endl;
    		}
		}
		
		if (selectInterval == 4){
			string time[5] = {"18.30 - 19.40", "19.45 - 20.55", "21.00 - 22.10", "22.30 - 23.40", "23.00 - 00.10"};

			for (int i = 0; i < 5; i++) {
    			cout << setw(15) << time[i] << setw(15) << nameCarrier[random[i]];
  
    			for (int j = 0; j < 5; j++) {
					if (nameCarrier[random[j]] == "Yaudah") {
						price2[j] = price1 * multiCarrier[0];
					}
					else if (nameCarrier[random[j]] == "SitiLing") {
						price2[j] = price1 * multiCarrier[1];
					}
					else if (nameCarrier[random[j]] == "MaungAir") {
						price2[j] = price1 * multiCarrier[2];
					}
					else if (nameCarrier[random[j]] == "WaterAsia") {
						price2[j] = price1 * multiCarrier[3];
					}
					else if (nameCarrier[random[j]] == "KotekaAir") {
						price2[j] = price1 * multiCarrier[4];
					}
    			}
			cout << setw(30) << price2[i] << endl;
			}
		}
	}
	
	if (timeMulti == 5 || timeMulti == 13 || timeMulti == 10 || timeMulti == 46 || timeMulti == 229){
		if (selectInterval == 1){
			string time[5] = {"00.20 - 01.40", "01.35 - 02.55", "02.50 - 04.10", "04.20 - 05.40", "04.50 - 06.10"};

			for (int i = 0; i < 5; i++) {
    			nameCarrier[random[i]];
    		}
    		
    		for (int j = 0; j < 5; j++) {
				if (nameCarrier[random[j]] == "Yaudah") {
					price2[j] = price1 * multiCarrier[0];
				}
				if (nameCarrier[random[j]] == "SitiLing") {
					price2[j] = price1 * multiCarrier[1];
				}
				if (nameCarrier[random[j]] == "MaungAir") {
					price2[j] = price1 * multiCarrier[2];
				}
				if (nameCarrier[random[j]] == "WaterAsia") {
					price2[j] = price1 * multiCarrier[3];
				}
				if (nameCarrier[random[j]] == "KotekaAir") {
					price2[j] = price1 * multiCarrier[4];
				}
    		}
    		
    		for (int i = 0; i < 5; i++) {
    			cout << (i + 1) << ") " << time[i] << setw(15) << nameCarrier[random[i]] << setw(30) << price2[i] << endl;
    		}
		}
 	
		if (selectInterval == 2){
			string time[5] = {"06.20 - 07.40", "07.35 - 08.55", "08.50 - 10.10", "10.20 - 11.40", "10.50 - 12.10"};

			for (int i = 0; i < 5; i++) {
    			nameCarrier[random[i]];
    		}
    		
    		for (int j = 0; j < 5; j++) {
				if (nameCarrier[random[j]] == "Yaudah") {
					price2[j] = price1 * multiCarrier[0];
				}
				if (nameCarrier[random[j]] == "SitiLing") {
					price2[j] = price1 * multiCarrier[1];
				}
				if (nameCarrier[random[j]] == "MaungAir") {
					price2[j] = price1 * multiCarrier[2];
				}
				if (nameCarrier[random[j]] == "WaterAsia") {
					price2[j] = price1 * multiCarrier[3];
				}
				if (nameCarrier[random[j]] == "KotekaAir") {
					price2[j] = price1 * multiCarrier[4];
				}
    		}
    		
    		for (int i = 0; i < 5; i++) {
    			cout << (i + 1) << ") " << time[i] << setw(15) << nameCarrier[random[i]] << setw(30) << price2[i] << endl;
    		}
		}
		
		if (selectInterval == 3){
			string time[5] = {"12.20 - 13.40", "13.35 - 14.55", "14.50 - 16.10", "16.20 - 17.40", "16.50 - 18.10"};

			for (int i = 0; i < 5; i++) {
    			nameCarrier[random[i]];
    		}
    		
    		for (int j = 0; j < 5; j++) {
				if (nameCarrier[random[j]] == "Yaudah") {
					price2[j] = price1 * multiCarrier[0];
				}
				if (nameCarrier[random[j]] == "SitiLing") {
					price2[j] = price1 * multiCarrier[1];
				}
				if (nameCarrier[random[j]] == "MaungAir") {
					price2[j] = price1 * multiCarrier[2];
				}
				if (nameCarrier[random[j]] == "WaterAsia") {
					price2[j] = price1 * multiCarrier[3];
				}
				if (nameCarrier[random[j]] == "KotekaAir") {
					price2[j] = price1 * multiCarrier[4];
				}
    		}
    		
    		for (int i = 0; i < 5; i++) {
    			cout << (i + 1) << ") " << time[i] << setw(15) << nameCarrier[random[i]] << setw(30) << price2[i] << endl;
    		}
		}

		if (selectInterval == 4){
			string time[5] = {"18.20 - 19.40", "19.35 - 20.55", "20.50 - 22.10", "22.20 - 23.40", "22.50 - 00.10"};

			for (int i = 0; i < 5; i++) {
    			nameCarrier[random[i]];
    		}
    		
    		for (int j = 0; j < 5; j++) {
				if (nameCarrier[random[j]] == "Yaudah") {
					price2[j] = price1 * multiCarrier[0];
				}
				if (nameCarrier[random[j]] == "SitiLing") {
					price2[j] = price1 * multiCarrier[1];
				}
				if (nameCarrier[random[j]] == "MaungAir") {
					price2[j] = price1 * multiCarrier[2];
				}
				if (nameCarrier[random[j]] == "WaterAsia") {
					price2[j] = price1 * multiCarrier[3];
				}
				if (nameCarrier[random[j]] == "KotekaAir") {
					price2[j] = price1 * multiCarrier[4];
				}
    		}
    		
    		for (int i = 0; i < 5; i++) {
    			cout << (i + 1) << ") " << time[i] << setw(15) << nameCarrier[random[i]] << setw(30) << price2[i] << endl;
    		}
		}
	}
	
	if (timeMulti == 11 || timeMulti == 23 || timeMulti == 34) {
		if (selectInterval == 1){
			string time[5] = {"00.00 - 01.30", "01.00 - 02.30", "02.00 - 03.30", "03.00 - 04.30", "04.00 - 05.30"};

		for (int i = 0; i < 5; i++) {
    			nameCarrier[random[i]];
    		}
    		
    		for (int j = 0; j < 5; j++) {
				if (nameCarrier[random[j]] == "Yaudah") {
					price2[j] = price1 * multiCarrier[0];
				}
				if (nameCarrier[random[j]] == "SitiLing") {
					price2[j] = price1 * multiCarrier[1];
				}
				if (nameCarrier[random[j]] == "MaungAir") {
					price2[j] = price1 * multiCarrier[2];
				}
				if (nameCarrier[random[j]] == "WaterAsia") {
					price2[j] = price1 * multiCarrier[3];
				}
				if (nameCarrier[random[j]] == "KotekaAir") {
					price2[j] = price1 * multiCarrier[4];
				}
    		}
    		
    		for (int i = 0; i < 5; i++) {
    			cout << (i + 1) << ") " << time[i] << setw(15) << nameCarrier[random[i]] << setw(30) << price2[i] << endl;
    		}
		}
		
		if (selectInterval == 2){
			string time[5] = {"06.00 - 07.30", "07.00 - 08.30", "08.00 - 09.30", "09.00 - 10.30", "10.00 - 11.30"};

			for (int i = 0; i < 5; i++) {
    			nameCarrier[random[i]];
    		}
    		
    		for (int j = 0; j < 5; j++) {
				if (nameCarrier[random[j]] == "Yaudah") {
					price2[j] = price1 * multiCarrier[0];
				}
				if (nameCarrier[random[j]] == "SitiLing") {
					price2[j] = price1 * multiCarrier[1];
				}
				if (nameCarrier[random[j]] == "MaungAir") {
					price2[j] = price1 * multiCarrier[2];
				}
				if (nameCarrier[random[j]] == "WaterAsia") {
					price2[j] = price1 * multiCarrier[3];
				}
				if (nameCarrier[random[j]] == "KotekaAir") {
					price2[j] = price1 * multiCarrier[4];
				}
    		}
    		
    		for (int i = 0; i < 5; i++) {
    			cout << (i + 1) << ") " << time[i] << setw(15) << nameCarrier[random[i]] << setw(30) << price2[i] << endl;
    		}
		}
 	
		if (selectInterval == 3){
			string time[5] = {"12.00 - 13.30", "13.00 - 14.30", "14.00 - 15.30", "15.00 - 16.30", "16.00 - 17.30"};

		for (int i = 0; i < 5; i++) {
    			nameCarrier[random[i]];
    		}
    		
    		for (int j = 0; j < 5; j++) {
				if (nameCarrier[random[j]] == "Yaudah") {
					price2[j] = price1 * multiCarrier[0];
				}
				if (nameCarrier[random[j]] == "SitiLing") {
					price2[j] = price1 * multiCarrier[1];
				}
				if (nameCarrier[random[j]] == "MaungAir") {
					price2[j] = price1 * multiCarrier[2];
				}
				if (nameCarrier[random[j]] == "WaterAsia") {
					price2[j] = price1 * multiCarrier[3];
				}
				if (nameCarrier[random[j]] == "KotekaAir") {
					price2[j] = price1 * multiCarrier[4];
				}
    		}
    		
    		for (int i = 0; i < 5; i++) {
    			cout << (i + 1) << ") " << time[i] << setw(15) << nameCarrier[random[i]] << setw(30) << price2[i] << endl;
    		}
		}
		
		if (selectInterval == 4){
			string time[5] = {"18.00 - 19.30", "19.00 - 20.30", "20.00 - 21.30", "21.00 - 22.30", "22.00 - 23.30"};

			for (int i = 0; i < 5; i++) {
    			nameCarrier[random[i]];
    		}
    		
    		for (int j = 0; j < 5; j++) {
				if (nameCarrier[random[j]] == "Yaudah") {
					price2[j] = price1 * multiCarrier[0];
				}
				if (nameCarrier[random[j]] == "SitiLing") {
					price2[j] = price1 * multiCarrier[1];
				}
				if (nameCarrier[random[j]] == "MaungAir") {
					price2[j] = price1 * multiCarrier[2];
				}
				if (nameCarrier[random[j]] == "WaterAsia") {
					price2[j] = price1 * multiCarrier[3];
				}
				if (nameCarrier[random[j]] == "KotekaAir") {
					price2[j] = price1 * multiCarrier[4];
				}
    		}
    		
    		for (int i = 0; i < 5; i++) {
    			cout << (i + 1) << ") " << time[i] << setw(15) << nameCarrier[random[i]] << setw(30) << price2[i] << endl;
    		}
    	}
	}

	if (timeMulti == 17 || timeMulti == 69) {
		if (selectInterval == 1){
			string time[5] = {"00.00 - 01.40", "01.00 - 02.40", "02.00 - 03.40", "03.00 - 04.40", "04.00 - 05.40"};

			for (int i = 0; i < 5; i++) {
    			nameCarrier[random[i]];
    		}
    		
    		for (int j = 0; j < 5; j++) {
				if (nameCarrier[random[j]] == "Yaudah") {
					price2[j] = price1 * multiCarrier[0];
				}
				if (nameCarrier[random[j]] == "SitiLing") {
					price2[j] = price1 * multiCarrier[1];
				}
				if (nameCarrier[random[j]] == "MaungAir") {
					price2[j] = price1 * multiCarrier[2];
				}
				if (nameCarrier[random[j]] == "WaterAsia") {
					price2[j] = price1 * multiCarrier[3];
				}
				if (nameCarrier[random[j]] == "KotekaAir") {
					price2[j] = price1 * multiCarrier[4];
				}
    		}
    		
    		for (int i = 0; i < 5; i++) {
    			cout << (i + 1) << ") " << time[i] << setw(15) << nameCarrier[random[i]] << setw(30) << price2[i] << endl;
    		}
		}
		
		if (selectInterval == 2){
			string time[5] = {"06.00 - 07.40", "07.00 - 08.40", "08.00 - 09.40", "09.00 - 10.40", "10.00 - 11.40"};

			for (int i = 0; i < 5; i++) {
    			nameCarrier[random[i]];
    		}
    		
    		for (int j = 0; j < 5; j++) {
				if (nameCarrier[random[j]] == "Yaudah") {
					price2[j] = price1 * multiCarrier[0];
				}
				if (nameCarrier[random[j]] == "SitiLing") {
					price2[j] = price1 * multiCarrier[1];
				}
				if (nameCarrier[random[j]] == "MaungAir") {
					price2[j] = price1 * multiCarrier[2];
				}
				if (nameCarrier[random[j]] == "WaterAsia") {
					price2[j] = price1 * multiCarrier[3];
				}
				if (nameCarrier[random[j]] == "KotekaAir") {
					price2[j] = price1 * multiCarrier[4];
				}
    		}
    		
    		for (int i = 0; i < 5; i++) {
    			cout << (i + 1) << ") " << time[i] << setw(15) << nameCarrier[random[i]] << setw(30) << price2[i] << endl;
    		}
		}
	 	
		if (selectInterval == 3){
			string time[5] = {"12.00 - 13.40", "13.00 - 14.40", "14.00 - 15.40", "15.00 - 16.40", "16.00 - 17.40"};

			for (int i = 0; i < 5; i++) {
    			nameCarrier[random[i]];
    		}
    		
    		for (int j = 0; j < 5; j++) {
				if (nameCarrier[random[j]] == "Yaudah") {
					price2[j] = price1 * multiCarrier[0];
				}
				if (nameCarrier[random[j]] == "SitiLing") {
					price2[j] = price1 * multiCarrier[1];
				}
				if (nameCarrier[random[j]] == "MaungAir") {
					price2[j] = price1 * multiCarrier[2];
				}
				if (nameCarrier[random[j]] == "WaterAsia") {
					price2[j] = price1 * multiCarrier[3];
				}
				if (nameCarrier[random[j]] == "KotekaAir") {
					price2[j] = price1 * multiCarrier[4];
				}
    		}
    		
    		for (int i = 0; i < 5; i++) {
    			cout << (i + 1) << ") " << time[i] << setw(15) << nameCarrier[random[i]] << setw(30) << price2[i] << endl;
    		}
		}
		
		if (selectInterval == 4){
			string time[5] = {"18.00 - 19.40", "19.00 - 20.40", "20.00 - 21.40", "21.00 - 22.40", "22.00 - 23.40"};

			for (int i = 0; i < 5; i++) {
    			nameCarrier[random[i]];
    		}
    		
    		for (int j = 0; j < 5; j++) {
				if (nameCarrier[random[j]] == "Yaudah") {
					price2[j] = price1 * multiCarrier[0];
				}
				if (nameCarrier[random[j]] == "SitiLing") {
					price2[j] = price1 * multiCarrier[1];
				}
				if (nameCarrier[random[j]] == "MaungAir") {
					price2[j] = price1 * multiCarrier[2];
				}
				if (nameCarrier[random[j]] == "WaterAsia") {
					price2[j] = price1 * multiCarrier[3];
				}
				if (nameCarrier[random[j]] == "KotekaAir") {
					price2[j] = price1 * multiCarrier[4];
				}
    		}
    		
    		for (int i = 0; i < 5; i++) {
    			cout << (i + 1) << ") " << time[i] << setw(15) << nameCarrier[random[i]] << setw(30) << price2[i] << endl;
    		}
		}
	}

	cout << endl;
	cout << "Please choose the number correspond to the available routes = ";
	cin >> flightChoice;
	system ("CLS");
	
	passengerData passenger[numPassengers];
	
	for (int i = 0; i < numPassengers; i++) {
		cout << "Passenger " << (i + 1) << " Title (Mr/Ms): ";
		cin >> passenger[i].title;
		cout << "Passenger " << (i + 1) << " Age: ";
		cin >> passenger[i].age;
		cout << "Passenger " << (i + 1) << " First Name: ";
		cin >> passenger[i].name.first;
		cout << "Passenger " << (i + 1) << " Last Name: ";
		cin >> passenger[i].name.last;
		cout << passenger[i].title << ". " << passenger[i].name.first << " " << passenger[i].name.last << " ID Number (6 Digits): ";
		cin >> passenger[i].idNumber;
		cout << passenger[i].title << ". " << passenger[i].name.first << " " << passenger[i].name.last << " Nationality: ";
		cin >> passenger[i].nationality;
		cout << passenger[i].title << ". " << passenger[i].name.first << " " << passenger[i].name.last << " Phone Number: ";
		cin >> passenger[i].phoneNumber;
		cout << passenger[i].title << ". " << passenger[i].name.first << " " << passenger[i].name.last << " E-mail (without '@example.com'): ";
		cin >> passenger[i].email;
		cout << endl;
		cout << passenger[i].title << ". " << passenger[i].name.first << " " << passenger[i].name.last << " Baggage Weight (0 - 20 Kg): ";
		cin >> passenger[i].baggage.weight;
		cout << endl;
		LOOP2:
		choosingSeat();
		cout << passenger[i].title << ". " << passenger[i].name.first << " " << passenger[i].name.last << " Seat Row: ";
		cin >> passenger[i].seat.row;
		if (seatClass == 1 && passenger[i].seat.row <= 5) {
			cout << "Choose seat according to your seat class please." << endl;
			goto LOOP2;
		}
		if (seatClass == 2 && passenger[i].seat.row >= 5) {
			cout << "Choose seat according to your seat class please." << endl;
			goto LOOP2;
		}
		cout << passenger[i].title << ". " << passenger[i].name.first << " " << passenger[i].name.last << " Seat Column: ";
		cin >> passenger[i].seat.column;
		cout << endl;
		system ("CLS");
	}
	
	for (int l = 0; l < numPassengers; l++) {
		if (passenger[l].age >= 12) {
			passenger[l].ageGroup = "Adult";
		}
		else if (passenger[l].age >= 2) {
			passenger[l].ageGroup = "Child";
		}
		else {
			passenger[l].ageGroup = "Infant"; 
		}
	}
	
	cout << "=======================================================================================================================" << endl;
	cout << setw(8) << "ID Num" << setw(3) << " " << setw(10) << "Full" << setw(10) << "Name" << setw(8) << "Age" << setw(15) << "Nationality"
			<< setw(15) << "Phone" << setw(20) << "E-mail(@gmail.com)" << setw(12) << "Bag. Weight" << setw(7) << "Seat"
			<< endl;
	
	for (int j = 0; j < numPassengers; j++) {
		cout << setw(8) << passenger[j].idNumber << setw(3) << passenger[j].title << setw(10) << passenger[j].name.first
			<< setw(10) << passenger[j].name.last << setw(8) << passenger[j].ageGroup << setw(15) << passenger[j].nationality << setw(15) << passenger[j].phoneNumber
			<< setw(20) << passenger[j].email << setw(12) << passenger[j].baggage.weight << setw(6) << passenger[j].seat.row << passenger[j].seat.column
			<< endl;
	}
	cout << "=======================================================================================================================" << endl;
	cout << endl;
	
	int priceAdult = numAdult * price2[flightChoice - 1] * multiAge[0];
	int priceChild = numChild * price2[flightChoice - 1] * multiAge[1];
	int priceInfant = numInfant * price2[flightChoice - 1] * multiAge[2];
	
	int totalPrice = priceAdult + priceChild + priceInfant;
	
	int randomPayment;
	srand((unsigned)time(NULL));
	randomPayment = (rand() % 999);
	
	int virtualAccount;
	srand((unsigned)time(NULL));
	virtualAccount = (rand() % 9999999);
	
	LOOP:
	string confirm;
	cout << "TOTAL" << endl;
	cout << setw(15) << nameCarrier[random[flightChoice - 1]] << setw(15) << (totalPrice) << endl;
	cout << endl;
	cout << "Go to payment? (Yes/No)" << endl;
	cout << "Input : ";
	cin >> confirm;
	system("CLS");
	
	if (confirm == "Yes"|| confirm == "yes"||confirm == "y") {
		cout << "Bank Transfer" << endl;
		for (int i = 0; i < 4; i++){
			cout << (i + 1) << ") " << bank[i] << endl;
		}
		
		int selectPayment;
		cout << "Select Bank : ";
		cin >> selectPayment;
		cout << endl;
		
		if (selectPayment == 1) {
			cout << "Please transfer the exact amount shown" << endl;
			cout << "Virtual Account" << setw(2) << ": " <<  virtualAccount << endl;
			cout << "Total Price" << setw(6) << ": " << totalPrice + randomPayment << endl;
			cout << "Please complete the payment within 1 hour";	
		}
		
		if (selectPayment == 2) {
			cout << "Please transfer the exact amount shown" << endl;
			cout << "Virtual Account" << setw(2) << ": " <<  virtualAccount << endl;
			cout << "Total Price" << setw(6) << ": " << totalPrice + randomPayment << endl;
			cout << "Please complete the payment within 1 hour";	
		}
		
		if (selectPayment == 3) {
			cout << "Please transfer the exact amount shown" << endl;
			cout << "Virtual Account" << setw(2) << ": " <<  virtualAccount << endl;
			cout << "Total Price" << setw(6) << ": " << totalPrice + randomPayment << endl;
			cout << "Please complete the payment within 1 hour";	
		}
		
		if (selectPayment == 4) {
			cout << "Please transfer the exact amount shown" << endl;
			cout << "Virtual Account" << setw(2) << ": " <<  virtualAccount << endl;
			cout << "Total Price" << setw(6) << ": " << totalPrice + randomPayment << endl;
			cout << "Please complete the payment within 1 hour";	
		}
	}
	
	else {
		cout << "Are you sure you want to cancel? (Y/N)" << endl;
		string cancel;
		if (cancel == "Y" || cancel == "y") {
			int back = 0;
			book (back);
		}
		else {
			goto LOOP;
		}
	}
	
	string paymentDone;
	
	bool a = true;
	while (a == true) {
		cout << endl;
		cout << "Have completed the payment ? (Yes / No)" << endl;
		cout << "Input : ";
		cin >> paymentDone;
		cout << endl;
		system ("CLS");
		
		if (paymentDone == "Yes"|| paymentDone == "yes"|| paymentDone == "y"){
			int flightCode;
			srand((unsigned)time(NULL));
			flightCode = (rand() % 9999);
			
			LOOP3 :
			cout << "Airline Booking Code" << endl;
			bookingNum();
			cout << endl;
			cout << "==========================================================================" << endl;
			cout << nameCarrier[random[flightChoice-1]] << " " << "ID - " << flightCode << endl;
			cout << nameClass[seatClass - 1] << endl;
			cout << "==========================================================================" << endl;
			cout << departDate << "/" << departMonth << "/" << departYear << " -> " << setw(16) << namePort[fromAirport - 1] << endl;
			cout << setw(30) << namePort[toAirport - 1] << endl;
			cout << "==========================================================================" << endl;
			cout << "List of Passenger(s)" << endl;
			
			for (int i = 0; i < numPassengers; i++) {
				cout << passenger[i].title << ". "<< setw(8) << passenger[i].name.first << setw(8) << passenger[i].name.last << setw(8) << passenger[i].ageGroup << setw(5)
					 << passenger[i].baggage.weight << " Kg" << setw(5) << passenger[i].seat.row << passenger[i].seat.column << endl;  
			}
			cout << "===================== Please take photo of your pass =====================" << endl;
			cout << endl;
			string m;
			cout << "Press 'm' to go back to the menu." << endl;
			cin >> m;
			system("CLS");
			if (m == "M" || m == "m") {
				a = false;
			}
		}
		else {
			a = true;
		}
	}
	
}

void choosingSeat() {
	int row;
	char column;
	string form[13][6];
	
	cout << setw(12) << "A" << setw(6) << "B" << setw(6) << "C" << setw(6)
					 << "D" << setw(6) << "E" << setw(6) << "F" << endl;
		
	for (int i = 0; i < 12; i++) {
		cout << left << setw(3) << "Row " << setw(2) << i + 1;
		for (int j = 0; j < 6; j++) {
			if (i == (row - 1) && j == static_cast<int>(column) - 65) {
				cout << right << setw(6) << "|X|";
			}
			else {
				cout << right << setw(6) << "|_|";
			}
		}
	cout << endl;
	cout << endl;
	}
	cout << "Row 1 to 5 are for Business Class." << endl;
	cout << "Row 6 to 13 are for Economy Class." << endl;
	cout << endl;
}

void menu2() {
	int n = 0;
	string option;
	cout << "1. Book a ticket" << endl;
	cout << "2. Check my booking" <<endl;
	cout << "What would you like to do? (1/2)" << endl;
	cout << "Input: ";
	cin >> option;
 
	system ("CLS");
 
	if (option == "1"){
		book(n);
	}
	else{
  		// ticket
	}
}

struct accountType {
	string username;
	string password;
};

struct loginType {
	string username;
	string password;
};

loginType login;
accountType account;

void registerAccount() {
	cout << "Input your username: ";
	cin >>  account.username;
	cout << endl;
	cout << "Input your password: ";
	cin >> account.password;
	cout << endl;
	system ("CLS");
}

void loginAccount() {
	cout << "Input your username: ";
	cin >> login.username;
	cout << endl;
	cout << "Input your password: ";
	cin >> login.password;
	system ("CLS");
 
	if (account.username == login.username && account.password == login.password) {
		menu2();
	}
	if (account.username == login.username && account.password != login.password) {
		cout << "Wrong Password!" << endl;
		cout << endl;
		loginAccount();
	}
	if (account.username != login.username && account.password == login.password) {
		cout << "Wrong Username!" << endl;
		cout << endl;
		loginAccount();
	}
	if (account.username != login.username && account.password != login.password) {
		cout << "Wrong Username and Password!" << endl;
		cout << endl;
		loginAccount();
	}
}

void menu() {
	string option;
 
	cout << "1. Register" << endl;
	cout << "2. Login" << endl;
	cout << "What would you like to do? (1/2)" <<endl;
	cout << "Input : ";
	cin >> option;
 
	system ("CLS");
 
	if (option == "1") {
		registerAccount();
	}
	else {
		loginAccount();
	}
}

int main(){
	cout << "======================================" << endl;
	cout << "========== WELCOME TO BO.COM =========" << endl;
	cout << "Your solution for budget-friendly trip" << endl;
	cout << "======================================" << endl;
	cout << endl;
	cout << "Created by: " << endl;
	cout << "1) Adityo Julian Tri WM" << endl;
	cout << "2) Farhan Falahaqil Rafi" << endl;
	cout << "3) Mochamad Hafidh Zuhdian" << endl;
	cout << endl;
	
	string a;
	cout << "Press any key(s) to continue: ";
	cin >> a;
	system("CLS");
	
	if (a == "a") {
		LOOP : menu();
		goto LOOP;
		cout << endl;
	}
	else {
		goto LOOP;
		cout << endl;
	}	
}

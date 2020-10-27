//////////////////////////////////////////////////////
//JHXie Combinational World                         //
//////////////////////////////////////////////////////
#if !defined(MainHeaderHpp_Included)
#define MainHeaderHpp_Included

#define Inputfile "input.txt"
#define Logfile "log.txt"
#define Outputfile "output.txt"
#define BUFFERSIZE 512
#define UnitNumber 9

#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>

using namespace std;
class Player;
class Game;	

class Player{
public:
	string Name;
	int alive_unit=UnitNumber;
	vector<vector<string>> Infantry_coordinate;
	vector<vector<string>> Cavalry_coordinate;
	vector<vector<string>> Artillery_coordinate;
	vector<vector<int>> Infantry_life;				//need to initialize
	vector<vector<int>> Cavalry_life;
	vector<vector<int>> Artillery_life;
	void Infantry(Player* Attacker, Player* Attacked, int flag);
	void Cavalry(Player* Attacker, Player* Attacked, int flag);
	void Artillery(Player* Attacker, Player* Attacked, int flag);
};
class Game{
public:
	const static int number_of_row;
	const static int number_of_column;
	static int row_of_table;
	static vector<string> Table;
	static vector<string> Log;
	static vector<string> Output;
	static Player P1;
	static Player P2;
	static void init();
	static void cycle();
	static void set();
	static void execute();
	static void calculate(Player* player);
	static void exit();
	static void generate_pattern();
};

vector<string> readfile();
void writefile(vector<string>* Log);
vector<string> split(string delim, string tgt);

#endif
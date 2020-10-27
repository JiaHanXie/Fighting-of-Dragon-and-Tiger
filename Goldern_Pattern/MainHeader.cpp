//////////////////////////////////////////////////////
//JHXie Combinational World                         //
//////////////////////////////////////////////////////
#include "MainHeader.hpp"
#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>

#define Inputfile "input.txt"
#define Logfile "log.txt"
#define Outputfile "output.txt"
#define BUFFERSIZE 512
#define Number_of_Row 6
#define Number_of_Column 6
#define UnitNumber 9
using namespace std;

const int Game::number_of_row=Number_of_Row;
const int Game::number_of_column=Number_of_Column;
int Game::row_of_table=0;
vector<string> Game::Table;
vector<string> Game::Log;
vector<string> Game::Output;

Player Game::P1;
Player Game::P2;

vector<string> readfile(){
	fstream ins_f;
	vector<string> Table;
	char line[BUFFERSIZE];
	ins_f.open(Inputfile);
	if(ins_f){
		while (ins_f.getline(line, BUFFERSIZE))
			Table.push_back(line);
		//cout << "size of Table: " << Table.size() << endl;
		Game::Log.push_back("size of Table: "+to_string(Table.size())+"\n");
		ins_f.close();
		return Table;
	}
	else{
		//cout << "error: input.txt not found\n";
		Game::Log.push_back("error: input.txt not found\n");
	}
}
void writefile(vector<string> &Log){
	ofstream out(Logfile);
	int i=0;
    while(i<Log.size()){
		out<< Log[i];
		i++;
	}
    out.close();
}
void Game::init(){
	Table.clear();
	Log.clear();
	Output.clear();
	Table=readfile();
	Log.push_back("read file...\n");
	Log.push_back("init...\n");
}
void Game::cycle(){
	for(int i=0;i<Table.size();i++){
		Game::set();
		Game::execute();
		Game::exit();
	}
}
void Game::set(){
	Player* master=NULL;
	vector<string> temp;
	vector<string> cmd;
	vector<int> temp_int;
	temp_int.clear();
	temp_int.push_back(0);
	cmd=split(" ", Table[row_of_table]);
	master=&P1;
	temp.clear();temp.push_back(cmd[0]);temp.push_back(cmd[1]);
	master->Infantry_coordinate.push_back(temp);
	master->Infantry_life.push_back(temp_int);
	temp.clear();temp.push_back(cmd[2]);temp.push_back(cmd[3]);
	master->Infantry_coordinate.push_back(temp);
	master->Infantry_life.push_back(temp_int);
	temp.clear();temp.push_back(cmd[4]);temp.push_back(cmd[5]);
	master->Infantry_coordinate.push_back(temp);
	master->Infantry_life.push_back(temp_int);
	temp.clear();temp.push_back(cmd[6]);temp.push_back(cmd[7]);
	master->Infantry_coordinate.push_back(temp);	
	master->Infantry_life.push_back(temp_int);
	temp.clear();temp.push_back(cmd[8]);temp.push_back(cmd[9]);
	master->Cavalry_coordinate.push_back(temp);
	master->Cavalry_life.push_back(temp_int);
	temp.clear();temp.push_back(cmd[10]);temp.push_back(cmd[11]);
	master->Cavalry_coordinate.push_back(temp);
	master->Cavalry_life.push_back(temp_int);
	temp.clear();temp.push_back(cmd[12]);temp.push_back(cmd[13]);
	master->Cavalry_coordinate.push_back(temp);
	master->Cavalry_life.push_back(temp_int);
	temp.clear();temp.push_back(cmd[14]);temp.push_back(cmd[15]);
	master->Artillery_coordinate.push_back(temp);
	master->Artillery_life.push_back(temp_int);
	temp.clear();temp.push_back(cmd[16]);temp.push_back(cmd[17]);
	master->Artillery_coordinate.push_back(temp);
	master->Artillery_life.push_back(temp_int);
	master=&P2;
	temp.clear();temp.push_back(cmd[18]);temp.push_back(cmd[19]);
	master->Infantry_coordinate.push_back(temp);
	master->Infantry_life.push_back(temp_int);
	temp.clear();temp.push_back(cmd[20]);temp.push_back(cmd[21]);
	master->Infantry_coordinate.push_back(temp);
	master->Infantry_life.push_back(temp_int);
	temp.clear();temp.push_back(cmd[22]);temp.push_back(cmd[23]);
	master->Infantry_coordinate.push_back(temp);
	master->Infantry_life.push_back(temp_int);
	temp.clear();temp.push_back(cmd[24]);temp.push_back(cmd[25]);
	master->Infantry_coordinate.push_back(temp);	
	master->Infantry_life.push_back(temp_int);
	temp.clear();temp.push_back(cmd[26]);temp.push_back(cmd[27]);
	master->Cavalry_coordinate.push_back(temp);
	master->Cavalry_life.push_back(temp_int);
	temp.clear();temp.push_back(cmd[28]);temp.push_back(cmd[29]);
	master->Cavalry_coordinate.push_back(temp);
	master->Cavalry_life.push_back(temp_int);
	temp.clear();temp.push_back(cmd[30]);temp.push_back(cmd[31]);
	master->Cavalry_coordinate.push_back(temp);
	master->Cavalry_life.push_back(temp_int);
	temp.clear();temp.push_back(cmd[32]);temp.push_back(cmd[33]);
	master->Artillery_coordinate.push_back(temp);
	master->Artillery_life.push_back(temp_int);
	temp.clear();temp.push_back(cmd[34]);temp.push_back(cmd[35]);
	master->Artillery_coordinate.push_back(temp);
	master->Artillery_life.push_back(temp_int);
	row_of_table=row_of_table+1;
	temp_int.clear();
	//cout << "set...\n";
	Log.push_back("set...\n");
}
void Game::execute(){
	Player* master=&P1;
	Player* slave=&P2;
	master->Infantry(master, slave, 0);
	master->Cavalry(master, slave, 0);
	master->Artillery(master, slave, 0);
	master=&P2;
	slave=&P1;
	master->Infantry(master, slave, 1);
	master->Cavalry(master, slave, 1);
	master->Artillery(master, slave, 1);
	//cout << "execute...\n";
	Log.push_back("execute...\n");
}
void Game::calculate(Player* player){
	for(int i=0;i<(player->Infantry_life).size();i++){
		int temp=0;
		for(int j=0;j<(player->Infantry_life[i]).size();j++){
			temp=temp+(player->Infantry_life[i][j]);
		}
		player->alive_unit=(player->alive_unit)-(temp>0);
	}
	for(int i=0;i<(player->Cavalry_life).size();i++){
		int temp=0;
		for(int j=0;j<(player->Cavalry_life[i]).size();j++){
			temp=temp+(player->Cavalry_life[i][j]);
		}
		player->alive_unit=(player->alive_unit)-(temp>0);
	}
	for(int i=0;i<(player->Artillery_life).size();i++){
		int temp=0;
		for(int j=0;j<(player->Artillery_life[i]).size();j++){
			temp=temp+(player->Artillery_life[i][j]);
		}
		player->alive_unit=(player->alive_unit)-(temp>0);
	}
	//cout << "calculate " << player->Name << endl;
	Log.push_back("calculate "+player->Name+"\n");
	Log.push_back("score: "+to_string(player->alive_unit)+"\n");
}
void Game::exit(){
	Player* p1=&P1;
	Player* p2=&P2;
	Game::calculate(p1);
	Game::calculate(p2);
	//cout << "Winner is Player " << (p1->alive_unit<p2->alive_unit) << endl;
	Log.push_back("Winner is Player "+to_string((p1->alive_unit<p2->alive_unit))+\
		"\n"+"exit...");
	Output.push_back(to_string((p1->alive_unit<p2->alive_unit))+"\n");
	writefile(Log);
	p1->alive_unit=UnitNumber;
	p1->Infantry_coordinate.clear();
	p1->Cavalry_coordinate.clear();
	p1->Artillery_coordinate.clear();
	p1->Infantry_life.clear();
	p1->Cavalry_life.clear();
	p1->Artillery_life.clear();
	p2->alive_unit=UnitNumber;
	p2->Infantry_coordinate.clear();
	p2->Cavalry_coordinate.clear();
	p2->Artillery_coordinate.clear();
	p2->Infantry_life.clear();
	p2->Cavalry_life.clear();
	p2->Artillery_life.clear();
}
void Game::generate_pattern(){
	ofstream out(Outputfile);
	int i=0;
    while(i<Output.size()){
		out<< Output[i];
		i++;
	}
    out.close();
}
vector<string> split(string delim, string tgt){
	vector<string> result;
	char* word=NULL;
	word=strtok(const_cast<char*>(tgt.c_str()), delim.c_str());
	while(word!=NULL){
		result.push_back(word);
		word=strtok(NULL, delim.c_str());
	}
	return result;
}
void Player::Infantry(Player* Attacker, Player* Attacked, int flag){
	for(int i=0;i<(Attacker->Infantry_coordinate).size();i++){
		int x=stoi(Attacker->Infantry_coordinate[i][0]);
		int y=stoi(Attacker->Infantry_coordinate[i][1]);
		for(int j=0;j<(Attacked->Infantry_coordinate).size();j++){
			if(flag==0){
				Attacked->Infantry_life[j].push_back(\
					(x==stoi(Attacked->Infantry_coordinate[j][0]))&&\
					((y+1)==stoi(Attacked->Infantry_coordinate[j][1])));
				Attacked->Infantry_life[j].push_back(\
					(x==stoi(Attacked->Infantry_coordinate[j][0]))&&\
					((y+2)==stoi(Attacked->Infantry_coordinate[j][1])));
			}else if(flag==1){
				Attacked->Infantry_life[j].push_back(\
					(x==stoi(Attacked->Infantry_coordinate[j][0]))&&\
					((y-1)==stoi(Attacked->Infantry_coordinate[j][1])));
				Attacked->Infantry_life[j].push_back(\
					(x==stoi(Attacked->Infantry_coordinate[j][0]))&&\
					((y-2)==stoi(Attacked->Infantry_coordinate[j][1])));
			}else{
				cout << "error: board wrong\n";
			}
		}
		for(int j=0;j<(Attacked->Cavalry_coordinate).size();j++){
			if(flag==0){
				Attacked->Cavalry_life[j].push_back(\
					(x==stoi(Attacked->Cavalry_coordinate[j][0]))&&\
					((y+1)==stoi(Attacked->Cavalry_coordinate[j][1])));
				Attacked->Cavalry_life[j].push_back(\
					(x==stoi(Attacked->Cavalry_coordinate[j][0]))&&\
					((y+2)==stoi(Attacked->Cavalry_coordinate[j][1])));
			}else if(flag==1){
				Attacked->Cavalry_life[j].push_back(\
					(x==stoi(Attacked->Cavalry_coordinate[j][0]))&&\
					((y-1)==stoi(Attacked->Cavalry_coordinate[j][1])));
				Attacked->Cavalry_life[j].push_back(\
					(x==stoi(Attacked->Cavalry_coordinate[j][0]))&&\
					((y-2)==stoi(Attacked->Cavalry_coordinate[j][1])));
			}else{
				cout << "error: board wrong\n";
			}
		}
	}
}
void Player::Cavalry(Player* Attacker, Player* Attacked, int flag){
	for(int i=0;i<(Attacker->Cavalry_coordinate).size();i++){
		int x=stoi(Attacker->Cavalry_coordinate[i][0]);
		int y=stoi(Attacker->Cavalry_coordinate[i][1]);
		for(int j=0;j<(Attacked->Cavalry_coordinate).size();j++){
			if(flag==0){
				Attacked->Cavalry_life[j].push_back(\
					((x+1)==stoi(Attacked->Cavalry_coordinate[j][0]))&&\
					((y+1)==stoi(Attacked->Cavalry_coordinate[j][1])));
				Attacked->Cavalry_life[j].push_back(\
					((x+2)==stoi(Attacked->Cavalry_coordinate[j][0]))&&\
					((y+2)==stoi(Attacked->Cavalry_coordinate[j][1])));
				Attacked->Cavalry_life[j].push_back(\
					((x-1)==stoi(Attacked->Cavalry_coordinate[j][0]))&&\
					((y+1)==stoi(Attacked->Cavalry_coordinate[j][1])));
				Attacked->Cavalry_life[j].push_back(\
					((x-2)==stoi(Attacked->Cavalry_coordinate[j][0]))&&\
					((y+2)==stoi(Attacked->Cavalry_coordinate[j][1])));
			}else if(flag==1){
				Attacked->Cavalry_life[j].push_back(\
					((x+1)==stoi(Attacked->Cavalry_coordinate[j][0]))&&\
					((y-1)==stoi(Attacked->Cavalry_coordinate[j][1])));
				Attacked->Cavalry_life[j].push_back(\
					((x+2)==stoi(Attacked->Cavalry_coordinate[j][0]))&&\
					((y-2)==stoi(Attacked->Cavalry_coordinate[j][1])));
				Attacked->Cavalry_life[j].push_back(\
					((x-1)==stoi(Attacked->Cavalry_coordinate[j][0]))&&\
					((y-1)==stoi(Attacked->Cavalry_coordinate[j][1])));
				Attacked->Cavalry_life[j].push_back(\
					((x-2)==stoi(Attacked->Cavalry_coordinate[j][0]))&&\
					((y-2)==stoi(Attacked->Cavalry_coordinate[j][1])));
			}else{
				cout << "error: board wrong\n";
			}
		}
		for(int j=0;j<(Attacked->Artillery_coordinate).size();j++){
			if(flag==0){
				Attacked->Artillery_life[j].push_back(\
					((x+1)==stoi(Attacked->Artillery_coordinate[j][0]))&&\
					((y+1)==stoi(Attacked->Artillery_coordinate[j][1])));
				Attacked->Artillery_life[j].push_back(\
					((x+2)==stoi(Attacked->Artillery_coordinate[j][0]))&&\
					((y+2)==stoi(Attacked->Artillery_coordinate[j][1])));
				Attacked->Artillery_life[j].push_back(\
					((x-1)==stoi(Attacked->Artillery_coordinate[j][0]))&&\
					((y+1)==stoi(Attacked->Artillery_coordinate[j][1])));
				Attacked->Artillery_life[j].push_back(\
					((x-2)==stoi(Attacked->Artillery_coordinate[j][0]))&&\
					((y+2)==stoi(Attacked->Artillery_coordinate[j][1])));
			}else if(flag==1){
				Attacked->Artillery_life[j].push_back(\
					((x+1)==stoi(Attacked->Artillery_coordinate[j][0]))&&\
					((y-1)==stoi(Attacked->Artillery_coordinate[j][1])));
				Attacked->Artillery_life[j].push_back(\
					((x+2)==stoi(Attacked->Artillery_coordinate[j][0]))&&\
					((y-2)==stoi(Attacked->Artillery_coordinate[j][1])));
				Attacked->Artillery_life[j].push_back(\
					((x-1)==stoi(Attacked->Artillery_coordinate[j][0]))&&\
					((y-1)==stoi(Attacked->Artillery_coordinate[j][1])));
				Attacked->Artillery_life[j].push_back(\
					((x-2)==stoi(Attacked->Artillery_coordinate[j][0]))&&\
					((y-2)==stoi(Attacked->Artillery_coordinate[j][1])));
			}else{
				cout << "error: board wrong\n";
			}
		}
	}
}
void Player::Artillery(Player* Attacker, Player* Attacked, int flag){
	for(int i=0;i<(Attacker->Artillery_coordinate).size();i++){
		int x=stoi(Attacker->Artillery_coordinate[i][0]);
		int y=stoi(Attacker->Artillery_coordinate[i][1]);
		for(int j=0;j<(Attacked->Artillery_coordinate).size();j++){
			Attacked->Artillery_life[j].push_back(\
					(x==stoi(Attacked->Artillery_coordinate[j][0])));
		}
		for(int j=0;j<(Attacked->Infantry_coordinate).size();j++){
			Attacked->Infantry_life[j].push_back(\
					(x==stoi(Attacked->Infantry_coordinate[j][0])));
		}
	}
}
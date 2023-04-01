#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int scoreCalculateByResult(string result){
    int score = 0;
    if (result == "lose") return score += 0;
    if (result == "draw") return score += 3;
    if (result == "win") return score += 6;
    return score;
}

int scoreCalculateByShape(string shape){
    int score = 0;
    if (shape == "A") return score += 1;
    if (shape == "B") return score += 2;
    if (shape == "C") return score += 3;
    return score;
}

int scoreCalculate(string shape, string result){
    return scoreCalculateByShape(shape) + scoreCalculateByResult(result);
}

string gameResult(string player){
    //A, X for Rock
    //B, Y for Paper
    //C, Z for Scissor
    string result;
    
    if (player == "X"){
       return result = "lose";
    }else if (player == "Y"){
       return result = "draw";
    }else return result = "win";
}

string playerAdjustment(string opponent, string result){
    if (opponent == "A"){
        if (result == "win"){
            return "B";
        }else if (result == "lose"){
            return "C";
        }else return opponent;
    }else if (opponent == "B"){
        if (result == "win"){
            return "C";
        }else if (result == "lose"){
            return "A";
        }else return opponent;
    }else{
        if (result == "win"){
            return "A";
        }else if (result == "lose"){
            return "B";
        }else return opponent;
    }
}

int main(){
    
    ifstream data("input.txt");
    string line;
    string opponent, player;
    int totalScore = 0;
    
    while(getline(data, line)){
        opponent = line[0];
        player = line[2];
        string result = gameResult(player);
        
        player = playerAdjustment(opponent, result);
        
        totalScore += scoreCalculate(player, result);
    }
    
    cout << totalScore << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <time.h>
using namespace std;
vector <string> shapes;
vector <string> shapes2;
vector <set<string>> cards;
void initShapes (){
    for (char c = 'A';c<='F';c++){
        string temp ="";
        temp+=c;
        shapes.push_back(temp);
        temp +="word1";
        shapes.push_back(temp);
        temp ="";
        temp+=tolower(c);
        shapes.push_back(temp);
        temp +="word2";
        shapes.push_back(temp);
    }
}
void fellcard (set<string> &card){

    int size =7+rand ()%2;
    int index=0;
    int numShapes = shapes.size();
    while (card.size()<size){
        index = rand()%numShapes;
        card.insert(shapes[index]);
    }
}
vector<string> countSemi (set<string>card , int cardindex){
    vector<string> semilarities;
    for (auto s:card){
        auto pos=cards[cardindex].find(s);
        if (pos!=cards[cardindex].end()){
            semilarities.push_back(s);
        }
    }
    return semilarities;
}
bool verify (set<string>card){
    for (int i=0;i<cards.size();i++){
        vector <string >semi = countSemi(card , i);
        if (semi.size()>3||semi.size()==0)return false;
    }
    return true;
}
void writeFile (){
    ofstream file ("cards.txt");
    for (auto c:cards){
        for (auto s:c){
            file<<s<<" ";
        }
        file<<endl;
    }
}
int main()
{
    set<string> card;
    srand (time(0));
    initShapes();

    while(cards.size()<21){
        fellcard(card);
        if (verify(card))
            cards.push_back(card);
        card.clear();
    }
    writeFile();
    return 0;
}

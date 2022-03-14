/**
 * @file mat.cpp
 * @author Ilan Gold (goldlmilan@gmail.com)
 * @brief https://codegolf.stackexchange.com/questions/241219/mat-printing-matrix
 * @version final Verison
 * @date 2022-03-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

namespace ariel{
string mat(int col,int row,char symb1 , char symb2){
    //The ASCII values allowed for the assigment.
    const int char_lim1=127;
    const int char_lim2=32;
    if(symb1<=char_lim2||symb1>=char_lim1|| symb2<=char_lim2||symb2>=char_lim1){
        throw runtime_error("ERR:The symbols cant be Special characters arguments!");
    }
    if (col%2==0 || row%2==0){
        throw runtime_error("ERR:col and row of the matrix need to be odd numbers");
        }
    if (col<=0 || row<=0){
        throw runtime_error("ERR:positive numbers only");
    }
    string ans;
    std::vector<std::vector<char>> matrix1; //A char matrix
    matrix1.resize(row, std::vector<char>(col));//the size of the matrix [Rows][col]
    int start_row=0;
    int end_row=row-1;
    int start_col=0;
    int end_col=col-1;
    bool turn=true;
    while (start_row<=end_row && start_col<=end_col)
    {
       //top row 
        for (int i = start_col; i <= end_col; i++)
        {
            if(turn){
                matrix1[start_row][i]=symb1;}
            else{
                matrix1[start_row][i]=symb2;}
        }

        start_row++;
        
        //right side colum
        for (int i = start_row; i <= end_row; i++)
        {   
            if(turn){
                matrix1[i][end_col]=symb1;}
            else{
                matrix1[i][end_col]=symb2;}
        }
        
        end_col--;
        
        //bottom row
            for (int i = end_col; i >= start_col; i--)
            {
                if(turn){
                    matrix1[end_row][i]=symb1;}
                else{
                    matrix1[end_row][i]=symb2;}    
        }
            end_row--;

        //left side col
            for (int i = end_row; i >= start_row; i--)
            {
                if(turn){
                    matrix1[i][start_col]=symb1;}
                else{
                    matrix1[i][start_col]=symb2;}     
        }
            start_col++; 
        turn=!turn; //Change the symb for the next iteration
    } 
    //copy the matrix to a String
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ans+=matrix1[i][j];
        }
            ans+="\n";
    }
    return ans;
}
}


/**
 * @brief Main for testing
 * 
 */
// int main(){
//     cout << ariel::mat(9, 7, 'a', 'b') << endl;
//     cout <<"-----------------------"<<endl;
//     cout << ariel::mat(9, 9, '@', '-') << endl;
//      return 1;
// }


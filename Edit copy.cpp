//part three to mitra project 

#include <iostream>
#include <string>
#include <list>
#include <algorithm>

//working edit distance function 

int edit_distance(std::string s1, std::string s2, int x, int y) // get length of string 1 and 2. 
{
    int distance[x+1][x+1];
    
    for(int i = 0; i <= x; ++i)
    {
        for(int j = 0; j <= y; ++j)
        {  
            if(i ==0)
                distance[i][j] = j;
            else if(j ==0)
                distance[i][j] = i;
            else if(s1[i-1] == s2[j-1])
                distance[i][j] = distance[i-1][j-1];
            else
            {   
                distance[i][j] = 1 + std::min(std::min(distance[i][j-1], distance[i-1][j]), distance[i-1][j-1]);
            }
            
        }
    }
    
    return distance[x][y];
}


/* 
    from driver, run this...

        std::cout << edit_distace(s1, s2, s1.length(), s2.length()) << std::endl; 

        */

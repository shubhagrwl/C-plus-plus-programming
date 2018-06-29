
#include <iostream>
#include <cstring>
using namespace std;

void removeDuplicates(char* str);
void removeAll(char* str, const char toRemove, int index);

inline void strtoupper(char* str) {
   while (*str) {
      *str = toupper(*str);
      ++str;
   }
}


void removeDuplicates(char* str)
{
    int i = 0;

    while(str[i] != '\0')
    {
        /* Remove all duplicate of character string[i] */
        removeAll(str, str[i], i + 1);
        i++;
    }
}

/**
 * Remove all occurrences of a given character from string.
 */
void removeAll(char* str, const char toRemove, int index)
{
    int i;

    while(str[index] != '\0')
    {
        /* If duplicate character is found */
        if(str[index] == toRemove)
        {
            /* Shift all characters from current position to one place left */
            i = index;
            while(str[i] != '\0')
            {
                str[i] = str[i + 1];
                i++;
            }
        }

        index++;
    }
}


int main()
{
    char ar[100],ch[100];
    int ctr,i,coun[26],x,l,a=0;
    cout<<"Enter the word : ";
    cin.getline(ar,100);


    strcpy(ch,ar);
    removeDuplicates(ch);
    strtoupper(ch);
    strtoupper(ar);

    for(i=0 ; i < strlen(ch) ; i++)
    {
        ctr=0;
        for(int j=0; j < strlen(ar);j++)
        {
            if(ar[j]==ch[i])
                ctr++;
        }
       coun[i]=ctr;
       // cout<<ch[i]<<"->"<<coun[i]<<"\n";
    }

    for(i=0 ; i < strlen(ch);i++)
    {
        cout<<"Character "<<i+1<<" is "<<ch[i]<<" length is "<<coun[i]<<"\n";
    }

    l = strlen(ch);
    x=coun[0];
    for(i=1 ; i != l ;i++)
    {
       if( x < coun[i])
         {x = coun[i];
          a=i;}

    }
    cout<<"\n\tHighest occurrence character is '"<<ch[a]<<"' occur -> "<<x<<" times\n";

}

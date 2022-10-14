/* Solution:
 * You need to eliminate all invalid space and add all valid space for original string.
 * Then reverse the whole string.
 * Reverse each words in above string at last.
 */
class Solution {
public:
    string reverseWords(string s) {
        int l = 0, f = 0; 
        //Step 1: Eliminate the spaces of source string:
        for(l,f;f<s.size();f++){
            if(s[f]!=' '){//When find the empty element:
                if(l!=0){//Check if the left pointer is in first position:
                         //If not: add a space(equivalent to add an " " before each valid words)
                         //If yes: jump it(Because the first pos cannot be " ")
                    s[l++] = ' ';
                }
                while(s[f]!=' '&&f<s.size()){//Eliminae all space in each words.
                    s[l] = s[f];
                    f++;
                    l++;
                }
            }
        }
        //Step 2: Cut string after the position l to eliminate the remain invalid elements.
        s.resize(l);
        //Step 3: After deleting all invalid space, reverse the whole string.
        reverse(s.begin(), s.end());
        //Step 4: Reverse each words in the reversed original string.
        for(int i=0,j=0;j<s.size();j++){
            if(s[j]==' '){//Key point1: You need to reverse each words:
                reverse(s.begin()+i, s.begin()+j);
                i=j+1;//Here must let i=j+1 because the position of l should be head of each words rather than the space gap.
            }
            if(j==s.size()-1){//Key point2: When arrive the last word where you cannot reverse by last space symbol:
                             //You need to use the position of j as the condition.
                reverse(s.begin()+i, s.begin()+j+1);
            }
        }
        return s;
    }
};
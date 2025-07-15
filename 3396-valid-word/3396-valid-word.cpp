class Solution {
public:
    bool isValid(string word) {
        bool b1=false;
        if(word.length()>=3) b1=true; //point 1
        else return false;
        bool b2=true;
        int vowel=0; int conso=0;
        for(int i=0;i<word.length();i++){
            if(word[i]>='0' && word[i]<='9')continue;
            else if((word[i]>='a' && word[i]<='z') || (word[i]>='A' && word[i]<='Z')){
                char k=toupper(static_cast<unsigned char>(word[i]));
                if(k=='A' || k=='E' || k=='I' || k=='O'|| k=='U') vowel++;
                else conso++;
                continue;
            } 
            else{b2=false;
            break;}
        }
        if(vowel>=1 && conso>=1){
            if(b1==true && b2==true){
                return true;
            }
        }
        return false;

    }

};
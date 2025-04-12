#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define Max_LANGTH 100
const char *preposition[] = {
    "about", "above", "across", "after", "against", "along", "among", "around",
    "at", "before", "behind", "below", "beneath", "beside", "between", "beyond",
    "by", "despite", "during", "except", "for", "from", "in", "inside",
    "into", "like", "near", "of", "off", "on", "onto", "out",
    "outside", "over", "past", "since", "through", "to", "toward",
    "under", "until", "up", "upon", "with", "within", "without"

};

int is_preposition(const char *word){
    for(int i = 0; i < sizeof(preposition)/sizeof(preposition[0]); i++){
        if(strcmp(word, preposition[i]) == 0){
            return 1;
        }
    }
    return 0;
};

void to_lowercase(char *str){
    for(int i = 0; str[i]; i++){
        str[i] = tolower(str[i]);
    }
};

int main(){
    char str[Max_LANGTH];
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; 

    char *word = strtok(str, " ");
    while(word != NULL){
        char temp[Max_LANGTH];
        strcpy(temp, word);
        to_lowercase(temp);
        if(is_preposition(temp)){
            printf("%s\n", word);
        }
        word = strtok(NULL, " ");
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void menu();

void menu() {
    printf("Main Menu\n");
        for (int i = 0; i < 30; i++)
            {
            printf("-");
            }
    printf("\nPlease Choose a Selection :) \n 1. Encrypt \n 2. Decrypt \n 3. Exit \n");
}

int encrypt(int str, int shiftKey) {
    if(str >= 'a' && str <= 'z'){
        return 'a' + ((str - 'a' + shiftKey) % 26);
    }
    else if(str >= 'A' && shiftKey <= 'Z'){
        return 'A' + ((str - 'A' + shiftKey) % 26);
    }
    else{
        return str;
    }
}

int decrypt(int str, int shiftKey) {
    if(str >= 'a' && str <= 'z'){
        return 'a' + ((str - 'a' + (26-shiftKey)) % 26);
    }
    else if(str >= 'A' && shiftKey <= 'Z'){
        return 'A' + ((str - 'A' + (26 - shiftKey)) % 26);
    }
    else{
        return str;
    }
}

int main(int argc, char *argv[]) {
    int opt, ch, key;
    //Loop until exit
    while(1) {
        menu(); //print menu
        scanf("%d", &opt);

        //functions time :D
        switch(opt){
            //Encrypt
            case 1:
                printf("\n**To Return to the Menu, press CTRL+D**");
                printf("\nEnter the shift key: ");
                scanf("%d", &key);
                printf("Enter the string to encrypt: ");
                    if(argc == 2) {     //run program with one command-line argument
                        key = atoi(argv[1]); //convert ASCII to integer for key entered
                    }
                while((ch = getchar()) != EOF) {
                    printf("%c", encrypt(ch, key));
                }
                printf("\n");
            break;
            //Decrypt 
            case 2:
                printf("**To Return to the Menu, press CTRL+D**");
                printf("\nEnter the shift key: ");
                scanf("%d", &key);
                printf("Enter the string to decrypt: ");
                    if(argc == 2) {
                        key = atoi(argv[1]);
                    }
                while((ch = getchar()) != EOF) {
                    printf("%c", decrypt(ch, key));
                }
            break;
            //Terminate Program :D
            case 3:
              printf("Terminating Caesar Cipher . . . Goodbye! :)");
              exit(0);
            break;
          default:
            printf("Not a valid entry. Please try again!\n\n");
        }
        
    }
    return 0;
}
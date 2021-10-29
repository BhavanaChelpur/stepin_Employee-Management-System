
int CEASER_DECRYPT()
{
char message[100], ch;
int i, key;
printf("Enter a message to decrypt: ");
getchar();
gets(message);
printf("Enter a numerical key: ");
scanf("%d", &key);
for(i = 0; message[i] != '\0'; ++i){
ch = message[i];
if(ch >= 'a' && ch <= 'z'){
ch = ch - key;
if(ch < 'a'){
ch = ch + 'z' - 'a' + 1;
}
message[i] = ch;
}
else if(ch >= 'A' && ch <= 'Z'){
ch = ch - key;
if(ch < 'A'){
ch = ch + 'Z' - 'A' + 1;
}
message[i] = ch;
}
}
printf("Decrypted message: %s \n", message);
return 0;
}


CEASER_ENCRYPT()
{
char message[100], ch;
int i, key;
printf("Enter a message to encrypt: ");
getchar();
fgets(message,100,stdin);
printf("Enter a numerical key: ");
scanf("%d", &key);
for(i = 0; message[i] != '\0'; ++i){
ch = message[i];
if(ch >= 'a' && ch <= 'z'){
ch = ch + key;
if(ch > 'z'){
ch = ch - 'z' + 'a' - 1;
}
message[i] = ch;
}
else if(ch >= 'A' && ch <= 'Z'){
ch = ch + key;
if(ch > 'Z'){
ch = ch - 'Z' + 'A' - 1;
}
message[i] = ch;
}
}
printf("Encrypted message: %s\n", message);
CEASER_DECRYPT();
}




 

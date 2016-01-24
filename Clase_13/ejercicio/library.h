#define MAX_QTY 200

typedef struct{
    char title[51];
    int code;
    int stock;
    int authorId;
    int status; /**< Active (1) or Inactive (0)  */
}book;


void setStatus(book bookArray[],int arrayLenght,int value);
int findEmptyPlace(book bookArray[],int arrayLenght);
int findBookByCode(book bookArray[],int arrayLenght,int code);
void orderArrayByTitle(book bookArray[],int arrayLenght);

void setBook(book bookArray[],int freePlaceIndex, int codeAux,char titleAux[], int authorIdAux,int stockAux);
void showArray(book bookArray[],int arrayLenght);

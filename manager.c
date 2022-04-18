// product.c
#include "manager.h"

int selectMenu(){
    int menu;
    printf("\n*** PizzaYaho ***\n");
    printf("1. 메뉴조회\n");
    printf("2. 메뉴추가\n");
    printf("3. 메뉴수정\n");
    printf("4. 메뉴삭제\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int createProduct(Product *p) {
        printf("제품명은? ");
        getchar();
        fgets(p->productName, PRO_NAME_SIZE, stdin);

        printf("제품 설명 입력 : ");
        getchar();
        fgets(p->explanation, EXPLANATION_SIZE, stdin);

        printf("중량 입력 : ");
        scanf("%s", p->weight);
        return 1;
}

void readProduct(Product p) {
    printf("%s %s %s\n", p.productName, p.explanation, p.weight);
}

int selectDataNo(Product *p[], int count){
    int num;
    listProduct(p, count);
    printf("번호 (취소:0)? ");
    scanf("%d", &num);
    return num;
}

int updateProduct(Product *p) {
        printf("새 제품명은? ");
        getchar();
        fgets(p->productName, PRO_NAME_SIZE, stdin);

        printf("새 제품 설명 입력 : ");
        getchar();
        fgets(p->explanation, EXPLANATION_SIZE, stdin);

        printf("새 중량 입력 : ");
        scanf("%s", p->weight);

        printf("업데이트 성공!\n");

        return 1;
}

int listProduct(Product *p[], int count) {
    for(int i = 0; i < count; i++) {
#ifdef DEBUG
    printf("%d\n", i+1);
#endif
        if(p[i] == NULL) continue;
        printf("%2d ", i+1);
        readProduct(*p[i]);
    }
    return 1;
}

//void saveData(Product *p, int count) {

//}

//void searchProduct(Product *p[], int count) {

//}

//void searchAscendingPrice(Product *p, int count) {

//}

//void searchKeyword(Product *p, int count) {

//}

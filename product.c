// product.c
#include "product.h"

int main() {
	Product p;
	
	int count = 0, menu;

	while(1) {
		menu = selectMenu();
		if (menu == 0) break;
		if(menu == 1 || menu == 3 || menu == 4)
			if(count == 0) continue;
		if (menu == 1){
			printf("***********************\n");
			readProduct(p);
		}
        	else if (menu == 2){
            		createProduct(&p);
            		count++;
        	}
        	else if (menu == 3){
            		updateProduct(&p);
        	}
        	else if (menu == 4){
            		deleteProduct(&p);
            		count--;
        	}
    	}
    	printf("종료됨!\n");

	return 0;
}

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
	if(p.productName != "\0") {
		printf("1. %s %s %s\n", p.productName, p.explanation, p.weight);	
	}
	else {
		printf("데이터 없음!!!\n");
	}
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

int deleteProduct(Product *p) {
	strcpy(p->productName,"\0");
    	printf("=> 삭제됨!\n");
	return 1;
}

//int listProduct(Product *p[], int count) {
		
//}

//void saveData(Product *p, int count) {

//}

//void searchProduct(Product *p[], int count) {

//}

//void searchAscendingPrice(Product *p, int count) {

//}

//void searchKeyword(Product *p, int count) {

//}

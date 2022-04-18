// product.h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PRO_NAME_SIZE 100
#define EXPLANATION_SIZE 1000
#define WEIGHT_SIZE 10

typedef struct{
    char productName[PRO_NAME_SIZE]; // 제품명
    char explanation[EXPLANATION_SIZE]; // 설명
    char weight[WEIGHT_SIZE]; // 중량 (문자열로 입력을 받는다)
    int price; // 판매가격
    int sendingType; // 보내는 방법
}Product;

int selectMenu();
int createProduct(Product *p); // 제품을 추가하는 함수
void readProduct(Product p); // 하나의 제품 출력 함수
int updateProduct(Product *p); // 제품을 업데이트하는 함수
int deleteProduct(Product *p); // 제품을 삭제하는 함수

int listProduct(Product *p[], int count); // 전체 등록된 제품 리스트 출력
int selectDataNo(Product *p[], int count);
// int loadData(Product *p); // file에서 불러오는 함수
// void saveData(Product *p, int count); // 현재 가지고 있는 제품의 데이터를 file에 저장하는 함수

// void searchProduct(Product *p[], int count); // 제품 이름 검색하는 함수
// void searchAscendingPrice(Product *p, int count); // 제품 값을 오름차순으로 정렬해 검색해주는 함수
// void searchKeyword(Product *p, int count); // keyword를 사용해서 원하고자 하는 문구가 설명에 들어있는 제품 검색하는 함수

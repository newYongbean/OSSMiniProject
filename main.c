// main.c
#include <stdio.h>
#include <string.h>
#include "manager.h"
#define DEBUG

int main() {
#ifdef DEBUG
        printf("Debug Mode\n");
#endif
        Product *p[SIZE];

        int count = 0, index = 0, menu, num;

        count = loadData(p);
        index = count;

        while(1) {
                menu = selectMenu();
                if (menu == 0) break;
                if(menu == 1 || menu == 3 || menu == 4)
                        if(count == 0) continue;
                if (menu == 1){
                        printf("***********************\n");
                        listProduct(p,count);
                }
                else if (menu == 2){
                        p[index] = (Product*)malloc(sizeof(Product));
                        count += createProduct(p[index++]);
                }
                else if (menu == 3){
                    num = selectDataNo(p, index);
                    if(num == 0){
                        printf("취소됨!\n");
                        continue;
                    }
                    updateProduct(p[num-1]);
                }
                else if (menu == 4){
                        num = selectDataNo(p, index);
                        if(num == 0) {
                            printf("=> 취소됨!\n");
                            continue;
                        }
                        int deleteok;
                        printf("정말로 삭제하시겠습니까? (삭제: 1)");
                        scanf("%d", &deleteok);
                        if(deleteok == 1)

                            if(&p[num-1]) 
#ifdef DEBUG
        printf("%s %s %s %d %d\n", p[num-1]->productName, p[num-1]->explanation, p[num-1]->weight, p[num-1]->price, p[num-1]->sendingType);
#endif
                                free(p[num-1]);
                            p[num-1] = NULL; 
                            count--;
                }
                else if(menu == 5){
                        saveData(p, count);
                }
                else if(menu == 6) {
                        searchProduct(p, count);
                }
                else if(menu == 6) {
                        printf("검색 방법 선택 (1. 제품 이름 검색, 2. 가격 오름차순 검색, 3. 키워드 검색) : ");
                        scanf("%d", &num);
                        if(num == 1){ 
                                searchProduct(&p[SIZE], count);
                        }
                        else if(num == 2) {
                                searchAscendingPrice(&p[SIZE], count);
                        }
                        else if(num == 3) {
                                searchKeyword(&p[SIZE], count);
                        }
                }
        }
        printf("종료됨!\n");

        return 0;
}

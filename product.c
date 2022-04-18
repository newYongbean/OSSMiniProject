#include "product.h"
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

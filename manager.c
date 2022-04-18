// manager.c
#include "manager.h"

int selectMenu(){
    int menu;
    printf("\n*** PizzaYaho ***\n");
    printf("1. 메뉴조회\n");
    printf("2. 메뉴추가\n");
    printf("3. 메뉴수정\n");
    printf("4. 메뉴삭제\n");
    printf("5. 메뉴저장\n");
    printf("6. 메뉴검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int selectDataNo(Product *p[], int count){
    int num;
    listProduct(p, count);
    printf("번호 (취소:0)? ");
    scanf("%d", &num);
    return num;
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

void saveData(Product *p[], int count) {
    FILE* fp;

	//중량 가격 제품명
	fp= fopen("product.txt","wt");
	for(int i = 0; i < count; i++) {
        if(p[i] == NULL) continue;
        fprintf(fp, "%s %s %s %d %d", p[i]->productName, p[i]->explanation, p[i]->weight, p[i]->price, p[i]->sendingType);
    }
	fclose(fp);
	printf("저장됨!\n");
}

int loadData(Product *p[]) {
    int count=0;
	FILE*fp;

	//파일 내용을 읽어와서 배열에 값 추가하기

    fp = fopen("product.txt", "rt");
    if(fp){
        for(; count < SIZE; count++) {
            fscanf(fp, "%s", p[count]->productName);
            if(feof(fp)) break;
            fscanf(fp, "%s", p[count]->explanation);
            fscanf(fp, "%s", p[count]->weight);
            fscanf(fp, "%d", &p[count]->price);
            fscanf(fp, "%d", &p[count]->sendingType);
        }

        fclose(fp);
        printf("=> 로딩 성공!\n");
    }
    else printf("=> 파일 없음");
    return count;
}

void searchProduct(Product *p[], int count) {
    int scount = 0;
    char search[SIZE];

    printf("검색할 이름? ");
    scanf("%s", search);

    printf("==============================\n");
    for(int i = 0; i < count; i++) {
        if(p[i] == NULL) continue;
        if(strstr(p[i]->productName, search)) {
            printf("%2d", i + 1);
            readProduct(*p[i]);
            scount++;
        }
    }
    if(scount == 0) printf("=> 검색된 데이터 없음!/n");
}

void searchAscendingPrice(Product *p[], int count) {
    int i, j, min;
    Product temp;
    for(i = 0; i < count; i++) {
        min = i;
        for(j = i + 1; j < count; j++)
            if(p[j]->price < p[min]->price)
                min = j;
        
        temp = (*p[i]);
        (*p[i]) = (*p[min]);
        (*p[min]) = temp;
    }
}

void searchKeyword(Product *p[], int count) {
    int scount = 0;
    char search[SIZE];

    printf("검색할 키워드는? ");
    scanf("%s", search);

    printf("==============================\n");
    for(int i = 0; i < count; i++) {
        if(p[i] == NULL) continue;
        if(strstr(p[i]->explanation, search)) {
            printf("%2d", i + 1);
            readProduct(*p[i]);
            scount++;
        }
    }
    if(scount == 0) printf("=> 검색된 데이터 없음!/n");
}

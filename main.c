#include <stdio.h>
#include "cJSON.h"

int CreateArryJsonString(void)
{
    cJSON *cJsonArr = cJSON_CreateArray();

    cJSON *sJsonObj1 = cJSON_CreateObject();
    cJSON_AddStringToObject(sJsonObj1, "test1", "test1");
    cJSON_AddStringToObject(sJsonObj1, "test11", "test1");

    cJSON *sJsonObj2 = cJSON_CreateObject();
    cJSON_AddStringToObject(sJsonObj2, "test2", "test2");
    cJSON_AddStringToObject(sJsonObj2, "test21", "test21");

    cJSON_AddItemToArray(cJsonArr, sJsonObj1);
    cJSON_AddItemToArray(cJsonArr, sJsonObj2);

    cJSON *pJson;
    pJson = cJSON_CreateObject();
    cJSON_AddItemToObject(pJson, "context", cJsonArr);

    char *pJsonSubData;
    pJsonSubData = cJSON_Print(pJson);
    cJSON_Minify(pJsonSubData);

    printf("test arry cjson string: %s \n", pJsonSubData);

    cJSON_Delete(cJsonArr);
    cJSON_Delete(pJson);
    free(sJsonObj1);
    free(sJsonObj2);

    return 1;
}

int main(void)
{
    int iRet = 0;

    printf("====> cJson Arry test start\n");
    iRet = CreateArryJsonString();
    printf("====> cJson Arry test end\n");

    return iRet;
}

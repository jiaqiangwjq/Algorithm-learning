/*
* 将顺序表 L 的所有元素逆置，要求算法复杂度为 O(1)
* 
* 思路: 扫描顺序表 L 的前半部分元素，将其与后半部分的对应元素交换
*/
void Reverse(Sqlist &L){
    ElemType temp;
    for(int i = 0; i < L.length/2; ++i){
        temp = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }
}
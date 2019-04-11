//흔한거

int add (int x, int y) {
	return x+y;
}
int sub (int x, int y) {
	return x-y;
}
int mul (int x, int y) {
	return x*y;
}
int div (int x, int y) {
	return x/y;
}

void input() {
	int a, b, z;
	char c;

	printf("연산자를 입력하시오 : ");
	scanf("%c",&c);
	printf("첫번째 숫자를 입력하시오 : ");
	scanf("%d",&a);
	printf("두번째 숫자를 입력하시오 : ");
	scanf("%d",&b);

	if (c == '+')
		z = add(a,b);
	if (c == '-')
		z = sub(a,b);
	if (c == '*')
		z = mul(a,b);
	if (c == '/')
		z = div(a,b);

	printf("연산값은 %d입니다.\n", z);

}


/* 2022/12/17
跟 compiler 相關的題目，用 stack 解
想用 switch 不過 char* 不能用
靈機一動我看第一個字元就好
不小心忽略會有負數，所以遇到 '-' 開頭要再確認字串長度
用 int 當 stack 會 overflow 所以改用 long long
*/
int evalRPN(char ** tokens, int tokensSize){
  int top = 0;
  long long stack[10001];
  for (int i = 0; i < tokensSize; i++) {
    switch (tokens[i][0]) {
      case '+':
        stack[top-2] = stack[top-2] + stack[top-1];
        printf("%s %d\n", tokens[i], stack[top-2]);
        top--;
        break;
      case '-':
        if(strlen(tokens[i]) == 1) {
          stack[top-2] = stack[top-2] - stack[top-1];
        printf("%s %d\n", tokens[i], stack[top-2]);
          top--;
        } else {
          stack[top++] = atol(tokens[i]);
        }
        break;
      case '*':
        stack[top-2] = stack[top-2] * stack[top-1];
        printf("%s %d\n", tokens[i], stack[top-2]);
        top--;
        break;
      case '/':
        stack[top-2] = stack[top-2] / stack[top-1];
        printf("%s %d\n", tokens[i], stack[top-2]);
        top--;
        break;
      default:
        printf("%d\n", atol(tokens[i]));
        stack[top++] = atol(tokens[i]);
        break;
      }
  }
    return stack[top-1];
}

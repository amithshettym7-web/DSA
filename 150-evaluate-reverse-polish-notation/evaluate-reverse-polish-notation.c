int evalRPN(char** arr, int n) {
    int stack[10000];
    int top = -1;
    for (int i = 0; i < n; i++)
    {
     if (isdigit(arr[i][0]) || 
            (arr[i][0] == '-' && isdigit(arr[i][1])))
        {
            stack[++top] = atoi(arr[i]);
        }
        else 
        {
            int b = stack[top--];
            int a = stack[top--];

            if (arr[i][0] == '+')
                  stack[++top] = a + b;
            else if (arr[i][0] == '-')
                stack[++top] = a - b;
            else if (arr[i][0] == '*')
                  stack[++top] = a * b;
            else if (arr[i][0] == '/')
                 stack[++top] = a / b;
        }
    }

    return stack[top];
}
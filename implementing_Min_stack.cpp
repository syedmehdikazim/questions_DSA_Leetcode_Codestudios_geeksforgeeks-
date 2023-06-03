class minStack
{
private:
    int *arr;
	int *arrkeep;
    int size;
    int topp;
	

public:
    // Constructor
    minStack()
    {
        size = 10001;
        arr = new int[size];
		arrkeep= new int[size];
        topp = -1;
		
    }

    // Function to add another element equal to num at the top of stack.
    void push(int num)
    {
		
        if (topp == size - 1)
        {
            return; // Stack is full, cannot push more elements
        }
        if (topp == -1)
        {
            topp++;
            arr[topp] = num;
			arrkeep[topp]=num;
        }
        else
        {
           /* if (num > arr[topp])
            {
                arr[topp + 1] = arr[topp];
                arr[topp] = num;
            }
            else*/ 
         arr[topp + 1] = num;
		 if ( arr[topp+1] < arrkeep[topp])
            {
                
				arrkeep[topp+1]=arr[topp+1];
            }
		else
		{
			arrkeep[topp+1]=arrkeep[topp];
		}
            
            topp++;
        }
    }

    // Function to remove the top element of the stack.
    int pop()
    {
        if (topp >= 0)
        {
            int element = arr[topp];
            topp--;
            return element;
        }
        else
        {
            return -1; // Stack is empty
        }
    }

    // Function to return the top element of stack if it is present. Otherwise return -1.
    int top()
    {
        if (topp >= 0)
        {
            return arr[topp];
        }
        else
        {
            return -1; // Stack is empty
        }
    }

    // Function to return minimum element of stack if it is present. Otherwise return -1.
    int getMin()
    {
        if (topp >= 0)
        {
            return arrkeep[topp];
        }
        else
        {
            return -1; // Stack is empty
        }
    }
};

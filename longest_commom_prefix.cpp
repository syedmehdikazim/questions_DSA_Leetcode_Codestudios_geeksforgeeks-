string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans;

    // Check the characters at each position
    for (int i = 0; i < arr[0].length(); i++)
    {
        char ch = arr[0][i];

        // Compare the character at position i in each string
        for (int j = 0; j < n; j++)
        {
            // If the character doesn't match, break the loop
            if (arr[j][i] != ch)
            {
                return ans;
            }
        }

        // All characters at position i match, add it to the prefix
        ans.push_back(ch);
    }

    return ans;
}

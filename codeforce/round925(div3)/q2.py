# Open input.txt for reading and output.txt for writing
with open('input.txt', 'r') as infile, open('output.txt', 'w') as outfile:
    t = int(infile.readline().strip())  # Read the number of test cases
    for i in range(t):
        n, p = map(int, infile.readline().split())  # Read values of n and p
        p /= 100
        q = p ** ((n - 1) / n)
        result = (q - p) * 100
        # Write the result to output.txt
        outfile.write(f"Case #{i + 1}: {result }\n")

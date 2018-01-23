'''
Kristina R Kolibab
Professor Tamon - CS 456
Homework 1 - Frequency Cipher

How to Execute:
    Python3 decryption.py (The file my program pulls is called a1.cipher)

'''
import string, random

# G L O B A L S
alpha = string.ascii_uppercase
   
# counts the frequency of letters in list
def count_frequency(my_list):
    temp_m_freq = [0] * len(alpha)
    for c in my_list:
        temp_m_freq[alpha.index(c)] += 1       
    
    return temp_m_freq
 
# finds the list of keys to decipher the message m   
def find_key(global_freq, my_freq):
    temp_m_freq = my_freq[:] 
    temp_g_freq = global_freq[:]
    key = [None] * 26
    
    for c in my_freq:
        letter = temp_g_freq[0]        
       
        max_m_freq = max(temp_m_freq)
        m_index = temp_m_freq.index(max_m_freq)
        key[m_index] = letter

        # Now they won't be found again with max()
        # but the index won't get messed up
        temp_m_freq[m_index] = -1
        temp_g_freq.pop(0) # removes first item in list

    return key    

# Decipher with key k and message m
def decipher(k, m): 
   
    new_m = [None] * len(m)
    i = 0
    for c in m:
        letter_index = alpha.index(c)
        new_letter = k[letter_index]
        new_m[i] = new_letter
        i += 1
    new_m = ''.join(new_m)
    return new_m

# writes the substitution table to a file
# frequency f, file name fname
def write_sub_table(f, fname):
    my_file = open(fname, 'w')
    n = 0
    for c in f:
        # A --> E
        my_file.write(alpha[n])
        my_file.write(" --> ")
        my_file.write(c)
        my_file.write("\n")
        n += 1
    my_file.close()

# starts with "Happy New Year"
def main():
    
    # read in the file
    f = open("a1.cipher")
    temp_array = [line.strip() for line in f.readlines()]
    m = ''.join(temp_array)
    f.close()
   
    # world frequency
    freq = ['E', 'T', 'I', 'O', 'N', 'S', 'R', 'A', 'U', 'M', 'H', 'P', 'L', \
        'Y', 'C', 'F', 'D', 'G', 'W', 'B', 'K', 'V', 'X', 'Q', 'J', 'Z']
    # frequency of my encrypted message
    m_freq = count_frequency(m)       
    # key 
    key = find_key(freq, m_freq)    
    # decrypted message
    new_m = decipher(key, m)

    # write substitution table to file
    write_sub_table(freq, "sub_table.txt")

    print("General Frequency Used: ", freq, "\n")
    print("Frequency of Message m:", m_freq, "\n")
    print("Key:", key, "\n")
    print("Message m:", m, "\n")
    print("New Message m:", new_m)

if __name__ == "__main__":
    main()






import csv
import sys
from sys import argv


def main():

    # TODO: Check for command-line usage
    if len(argv) != 3:
        print("Please, provide 2 command in line arguments")
        return

    # TODO: Read database file into a variable
    csv_file = argv[1]
    rows = []
    csv_file_path = f"databases/{csv_file}"
    with open(csv_file_path) as file:
        reader = csv.DictReader(file)
        print(reader.fieldnames)
        for row in reader:
            rows.append(row)
        print(rows)

    # TODO: Read DNA sequence file into a variable
    txt_file = argv[2]
    txt_file_path = f"sequences/{txt_file}"
    with open(txt_file_path) as file:
        dna_sequence  = file.read()
        print("DNA secuences: ")
        print(dna_sequence )

    # TODO: Find longest match of each STR in DNA sequence
        find_match = {str_name: longest_match(dna_sequence, str_name) for str_name in reader.fieldnames[1:]}
        print("longest match ", find_match)


    # TODO: Check database for matching profiles
        for profile in rows:
            if all(int(profile[str_name]) == find_match[str_name] for str_name in find_match):
                print("Matching individual:", profile['name'])
                return
            print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()

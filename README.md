# Checksum-Calculation-Program
 Developed a robust program to calculate 8, 16, and 32-bit checksums for text files, ensuring data integrity through precise checksum calculations. 

The project involved:

● Command Line Execution: Implemented the program to run from the terminal, accepting command line parameters for the input file and checksum size (8, 16, or 32 bits). This design ensures the program is versatile and can handle various checksum requirements.

● File Handling and Processing: Efficiently processed input files containing ASCII characters. The program read the entire file, ensuring non-alphabetic characters and spaces were correctly handled. It then echoed the processed input to the console, formatted in rows of exactly 80 characters each.

● Checksum Calculation: Implemented algorithms to compute 8, 16, and 32-bit checksums. This involved:

  ● Reading the input text and converting it into a format suitable for checksum calculation.
 
  ● Padding the input data with 'X' characters to ensure alignment with the specified checksum size.
 
  ● Computing the checksum by summing the ASCII values of the characters and applying modulo operations to fit the required checksum size.

● Output Formatting: The program output included:

  ● The echoed input text displayed in the specified format.
 
  ● The calculated checksum displayed in hexadecimal format, accurately reflecting the checksum size (8-bit: two hex characters, 16-bit: four hex characters, 32-bit: eight hex characters).
 
  ● The total character count, including the padding and newline characters, ensuring completeness and accuracy.
 
● Error Handling: The program included robust error handling, validating the checksum size parameter and providing clear error messages for invalid inputs, ensuring user-friendly interactions and reliability.

Skills: C (Programming Language) · File I/O Operations · Command-Line Interface (CLI) · Data Integrity and Validation · Algorithm Implementation · Software Development Lifecycle · Problem Solving

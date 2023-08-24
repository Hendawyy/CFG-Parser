# CFG-Parser
This repository contains a simple parser for a context-free grammar (CFG). The CFG is defined as follows:

```c
E --> TE^
T --> FT^
E^ --> +TE^ | NULL
T^ --> *FT^ | NULL
F --> (E) | a
```

## How to Use

1. Clone this repository:
```
git@github.com:Hendawyy/CFG-Parser.git
```
2. Compile the code
3. Run the parser
4. Enter a string to be parsed as per the CFG rules.

## Sample Usage

Here's an example of how to use the CFG parser:

The CFG:
```
E --> TE^
T --> FT^
E^ --> +TE^ | NULL
T^ --> *FT^ | NULL
F --> (E) | a
```

Enter a string to be parsed: 
```
a*a+(a+a)
```
Output
```
Action: E --> TE^
Action: T --> FT^
Action: F --> a Matching: 'a'
Action: T^ --> FT^ Matching: ''
Action: F --> a Matching: 'a'
Action: T^ --> NULL
Action: E^ --> +TE^ Matching: '+'
Action: T --> FT^
Action: F --> (E) Matching: '('
Action: E --> TE^
Action: T --> FT^
Action: F --> a Matching: 'a'
Action: T^ --> NULL
Matching: ')'
Action: E^ --> NULL
String is accepted
```

// #define T_SEMICOLON  ';'
#define T_LPAREN        '('
#define T_RPAREN        ')'
#define T_ASSIGN        '='
#define T_ADDITON       '+'
#define T_SUBSTRACTION  '-'
#define T_DIVIDE        '/'
#define T_MULTIPLY      '*'
#define T_EXPONENT      '^'
// #define T_WHILE  257
// #define T_IF  258
// #define T_RETURN  259
// ...
#define T_IDENTIFIER  268
#define T_INTEGER  269
#define T_DOUBLE   270
#define T_STRING  271
#define T_END  349
#define T_UNKNOWN  350
// use ASCII values for single char tokens
// reserved words
// identifiers, constants, etc.
// code used when at end of file
// token was unrecognized by scanner
struct token_t {
  int type;
  union {
    char stringValue[256];
    int intValue;
    double doubleValue;
} val; };
// one of the token codes from above
// holds lexeme value if string/identifier
// holds lexeme value if integer
// holds lexeme value if double
int main(int argc, char *argv[])
{
  struct token_t token;
  InitScanner();
   while (ScanOneToken(stdin, &token) != T_END)
    ; // this is where you would process each token
  return 0;
}
static void InitScanner()
{
  create_reserved_table();  // table maps reserved words to token type
  insert_reserved("WHILE", T_WHILE)
  insert_reserved("IF", T_IF)
  insert_reserved("RETURN", T_RETURN)
  ....
}
static int ScanOneToken(FILE *fp, struct token_t *token)
{
  int i, ch, nextch;
  ch = getc(fp);    // read next char from input stream
  while (isspace(ch))    // if necessary, keep reading til non-space char
    ch = getc(fp);    // (discard any white space)
  switch(ch) {
    case '/':    // could either begin comment or T_DIVIDE op
      nextch = getc(fp);
      if (nextch == '/' || nextch == '*')
        ; // here you would skip over the comment
      else
        ungetc(nextch, fp); // fall-through to single-char token case
    case ';': case ',': case '=':  // ... and other single char tokens
      token->type = ch; // ASCII value is used as token type
      return ch;     // ASCII value used as token type
    case 'A': case 'B': case 'C':   // ... and other upper letters
      token->val.stringValue[0] = ch;
      for (i = 1; isupper(ch = getc(fp)); i++) // gather uppercase
        token->val.stringValue[i] = ch;
      ungetc(ch, fp);
      token->val.stringValue[i] = '\0';  // lookup reserved word
      token->type = lookup_reserved(token->val.stringValue);
      return token->type;
    case 'a': case 'b': case 'c':  // ... and other lower letters
      token->type = T_IDENTIFIER;
      token->val.stringValue[0] = ch;
      for (i = 1; islower(ch = getc(fp)); i++)
3
token->val.stringValue[i] = ch; // gather lowercase
      ungetc(ch, fp);
      token->val.stringValue[i] = '\0';
      if (lookup_symtab(token->val.stringValue) == NULL)
        add_symtab(token->val.stringValue); // get symbol for ident
      return T_IDENTIFIER;
    case '0': case '1': case '2': case '3':  //....  and other digits
      token->type = T_INTEGER;
      token->val.intValue = ch - '0';
      while (isdigit(ch = getc(fp))) // convert digit char to number
        token->val.intValue = token->val.intValue * 10 + ch - '0';
      ungetc(ch, fp);
      return T_INTEGER;
    case EOF:
      return T_END;
    default:    // anything else is not recognized
      token->val.intValue = ch;
      token->type = T_UNKNOWN;
      return T_UNKNOWN;
} }
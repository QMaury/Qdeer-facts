/* qdeerfacts.c
 * QMaury <qmaury@goat.si>
 *
 * This is based off a program called sex.c that I did not write
 * https://spatula.net/software/sex/
 *
 * The original author of the code is not known.
 * If you are the original author or know the original author,
 * please contact <qmaury@goat.si> or <freebsd@spatula.net>
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

static char     *prompt[] = {
        "Did you know",         "It is observed that", "Typically,",
        "Generally,",           "Often times,",        "Sometimes,",
        "During nightfall,",    "Funnily,",            "Oddly,",
};

static char     *deers[] = {
        "deers",                "male deers",           "female deers",
};

static char     *verb[] = {
        "run on their hind legs","drink water",         "ejaculate",
        "speak",                "scream",               "shit",         "shit themselves",
        "fart",                 "piss",                 "die",
        "pass out",             "squirt",               "combust",
        "paint pretty paintings",       "drink heavily","shout",
        "read",                 "masturbate",           "jerk off",
        "fuck each other",      "have sex",             "laugh",
        "fall over",            "burp",                 "cry",
        "commit war crimes",    "eat food",             "frown",
        "write a C compiler",   "write a LISP interpreter",     "install Gentoo",
        "install Arch Linux",   "shoplift",             "stand on their hind legs",
        "stand on their front legs",                    "brush their teeth",
};

static char     *when[] = {
        "when they",            "if they",              "every time they",
        "because they",
};


static char     *reason[] = {
   "are hungry.",           "are bored.",       "feel masochistic.",
   "are sad.",              "are angry.",         "feel apathetic.",
   "are horny.",                 "are sleepy.",   "are furious.",  
   "need to shit.",         "need to piss.",      "are erect.",
   "are unhappy with their current operating system.",  "have diarrhea.",
   "are insecure about their penis size.",               "are thirsty.",
   "feel gross",                "feel naughty",
};

struct table {
        char    **item;
        short   len;
};

typedef struct table    TABLE;
#define SZ(a)           sizeof(a) / sizeof(char *)

TABLE   list[] = {
        {prompt,         SZ(prompt)},     {deers,           SZ(deers)},
        {verb,            SZ(verb)},        {when,           SZ(when)},
        {reason,         SZ(reason)},     {(char **)NULL,  (short)NULL},
};

#define LLINE   50
static short    lwidth;
static short    wraplen;

int main(int argc, char **argv)
{
   register TABLE  *ttp;
   register char   *cp;
   int     getpid();
   long     now;
   char buffer[2048];
   int pos, lastword;

   wraplen = 50;

   now = time(&now) / random();
   srandom(getpid() + (int)((now >> 16) + now + time(&now)));

   pos = lastword = 0;
   for (ttp = list;ttp->item;++ttp,++lwidth) {
      for (cp = ttp->len > 1 ? ttp->item[random() % ttp->len] :
           *ttp->item;*cp;++cp,++lwidth) {
	buffer[pos] = *cp;
	if ((wraplen > 0) && (lwidth >= wraplen)) {
	    buffer[lastword] = '\n';
	    lwidth = pos - lastword;
	}
	if (isspace(*cp)) {
	    lastword = pos;
	} 
	pos++;
      }
      buffer[pos] = ' ';
      lastword = pos++;
   }
   buffer[pos] = '\0';

   puts(buffer);

   return(0);
}

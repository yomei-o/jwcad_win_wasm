/* Esc and right-click in the middle of commands, against what the original
 * does (tools/escprobe3.sh, tmp/esc_report.md).
 *   tools/escprobe_port "name|cmd:32771;300,300;E;R;" ...   -> prints the R lines
 * (the same step strings tools/escprobe3.sh sends to the original).
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/app.h"
#include "../src/cmd.h"

int main(int argc, char **argv)
{
    FILE *f = fopen("tmp/esc5.jww", "rb");
    static unsigned char b[1 << 22];
    long n = f ? (long)fread(b, 1, sizeof b, f) : 0;
    int i;
    if (f) fclose(f);
    app_resize(1264, 741);
    if (!n || !app_open(b, n)) { printf("BAD open\n"); return 1; }
    for (i = 1; i < argc; i++) {
        char s[1000], *p, *q;
        strncpy(s, strchr(argv[i], '|') + 1, sizeof s - 1);
        s[sizeof s - 1] = 0;
        for (p = s; *p; p = q) {
            int x, y;
            q = strchr(p, ';');
            if (q) *q++ = 0; else q = p + strlen(p);
            if (!strncmp(p, "cmd:", 4)) app_command(atoi(p + 4));
            else if (!strcmp(p, "E")) app_key(27);
            else if (!strcmp(p, "N")) app_key(13);
            else if (!strcmp(p, "R")) { const char *t = jw_cmd_status(app_drawing()); printf("[ %s]\n", t ? t : ""); }
            else if (!strncmp(p, "raw:v,5136", 10)) jw_cmd_bar(app_drawing(), 1120);
            else if (*p == 'm' && sscanf(p + 1, "%d,%d", &x, &y) == 2) app_move(x + 78, y + 34);
            else if (!strncmp(p, "wait:", 5) || !strncmp(p, "shot:", 5)) ;
            else if (*p == 'r' && sscanf(p + 1, "%d,%d", &x, &y) == 2) app_press(x + 78, y + 34, 1);
            else if (sscanf(p, "%d,%d", &x, &y) == 2) app_press(x + 78, y + 34, 0);
        }
    }
    return 0;
}

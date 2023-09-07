#ifndef TINYFILEDIALOGS_H
#define TINYFILEDIALOGS_H

/*
if tinydialogs.c is compiled with a C++ compiler
rather than with a C compiler, you need to comment out:
extern "C" {
and the corresponding closing bracket:
}
*/

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

extern int tinyfd_forceConsole ; /* for UNIX only: 0 (default) or 1 */
/* 1 forces all dialogs into console mode even when the X server is present */
/* can be modified at run time */

char const * tinyfd_saveFileDialog (
    char const * const aTitle , /* "" */
    char const * const aDefaultPathAndFile , /* "" */
    int const aNumOfFileFilters , /* 0 */
    char const * const * const aFileFilters ) ; /* NULL or {"*.txt"} */

char const * tinyfd_openFileDialog (
    char const * const aTitle , /* "" */
    char const * const aDefaultPathAndFile , /* "" */
    int const aNumOfFileFilters , /* 0 */
    char const * const * const aFileFilters , /* NULL or {"*.jpg","*.png"} */
    int aAllowMultipleSelects ) ; /* 0 or 1 */
/* in case of multiple files, the separator is | */

char const * tinyfd_selectFolderDialog (
	char const * const aTitle , /* "" */
    char const * const aDefaultPath ) ; /* "" */

int tinyfd_messageDialog (
    char const * const aTitle , /* "" */
    char const * const aMessage , /* "" */ /* may contain \n and \t */
    char const * const aDialogType , /* "ok" "okcancel" "yesno" */
    char const * const aIconType , /* "info" "warning" "error" "question" */
    int const aDefaultButton ) ; /* 0 for cancel/no , 1 for ok/yes */
/* returns 0 for cancel/no , 1 for ok/yes */

char const * tinyfd_colorChooser(
	char const * const aTitle , /* "" */
	char const * const aDefaultHexRGB , /* NULL or "#FF0000" */
	unsigned char aDefaultRGB[3] , /* { 0 , 255 , 255 } */
	unsigned char aoResultRGB[3] ) ; /* { 0 , 0 , 0 } */
/* returns the hexcolor as a string "#FF0000" */
/* aoResultRGB also contains the result */
/* aDefaultRGB is used only if aDefaultHexRGB is NULL */
/* aDefaultRGB and aoResultRGB can be the same array */

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif /* TINYFILEDIALOGS_H */

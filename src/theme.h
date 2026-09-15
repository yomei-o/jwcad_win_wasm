/* The system colours the original picks up from Windows.
 *
 * Jw_cad asks GetSysColor for these, so strictly they are whatever the user's
 * theme says.  The reference screens were taken on the Windows 11 default
 * light theme; these are its values, and the port hardcodes them so that the
 * browser build cannot drift.
 */
#ifndef JW_THEME_H
#define JW_THEME_H

#define C_BTNFACE      0xf0f0f0u   /* COLOR_BTNFACE / COLOR_3DFACE       */
#define C_BTNHILIGHT   0xffffffu   /* COLOR_BTNHIGHLIGHT / COLOR_3DHILIGHT */
#define C_3DLIGHT      0xe3e3e3u   /* COLOR_3DLIGHT                      */
#define C_BTNSHADOW    0xa0a0a0u   /* COLOR_BTNSHADOW / COLOR_3DSHADOW   */
#define C_3DDKSHADOW   0x696969u   /* COLOR_3DDKSHADOW                   */
#define C_BTNTEXT      0x000000u   /* COLOR_BTNTEXT                      */
#define C_GRAYTEXT     0x6d6d6du   /* COLOR_GRAYTEXT, disabled captions  */
#define C_WINDOW       0xffffffu   /* COLOR_WINDOW, the drawing area     */

#endif

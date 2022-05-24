/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_keys.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:15:14 by ljohnson          #+#    #+#             */
/*   Updated: 2022/05/18 09:23:59 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_KEYS_H
# define RT_KEYS_H

// Keyboard First Row
// Q W E R T Y U I O P
# define K_Q 12
# define K_W 13
# define K_E 14
# define K_R 15
# define K_T 17
# define K_Y 16
# define K_U 32
# define K_I 34
# define K_O 31
# define K_P 35

// Keyboard Second Row
// A S D F G H J K L
# define K_A 0
# define K_S 1
# define K_D 2
# define K_F 3
# define K_G 5
# define K_H 4
# define K_J 38
# define K_K 40
# define K_L 37

//Keyboard Third Row
// Z X C V B N M
# define K_Z 6
# define K_X 7
# define K_C 8
# define K_V 9
# define K_B 11
# define K_N 45
# define K_M 46

// Keyboard Number Row
// 1 2 3 4 5 6 7 8 9 0 - = ~
# define K_1 18
# define K_2 19
# define K_3 20
# define K_4 21
# define K_5 23
# define K_6 22
# define K_7 26
# define K_8 28
# define K_9 25
# define K_0 29
# define K_MINUS 27
# define K_EQUAL 24
# define K_TILDE 50

// Keyboard Pav Num
// 0 1 2 3 4 5 6 7 8 9 / * - + .
# define PV_0 82
# define PV_1 83
# define PV_2 84
# define PV_3 85
# define PV_4 86
# define PV_5 87
# define PV_6 88
# define PV_7 89
# define PV_8 91
# define PV_9 92
# define PV_SLASH 75
# define PV_STAR 67
# define PV_MINUS 78
# define PV_PLUS 69
# define PV_ENT 76
# define PV_POINT 65

// Keyboard Meta Characters
// [ ] \ ; ' , . /
# define K_BRACKET1 33
# define K_BRACKET2 30
# define K_BACKSLASH 42
# define K_PCOMMA 41
# define K_QUOTE 39
# define K_COMMA 43
# define K_DOT 47
# define K_SLASH 44

// Keyboard Special characters
# define K_DEL 51
# define K_ESC 53
# define K_SP 49
# define K_CTL 256
# define K_ALT 261
# define K_CTLGR 269
# define K_ALTGR 262
# define K_CMD 259
# define K_ENT 36
# define K_SHIFT 257
# define K_SHIFTGR 258
# define K_MAJ 272
# define K_TAB 48
# define K_UP 126
# define K_LEFT 123
# define K_DOWN 125
# define K_RIGHT 124

/*
Code	|	Events

02		|	Key Press
03		|	Key Release
04		|	Button Press
05		|	Button Release
06		|	Motion Notify
07		|	Enter Notify
08		|	Leave Notify
09		|	Focus In
10		|	Focus Out
11		|	Keymap Notify
12		|	Expose
13		|	Graphics Expose
14		|	No Expose
15		|	Visibility Notify
16		|	Create Notify
17		|	Destroy Notify
18		|	Unmap Notify
19		|	Map Notify
20		|	Map Request
21		|	Reparent Notify
22		|	Configure Notify
23		|	Configure Request
24		|	Gravity Notify
25		|	Resize Request
26		|	Circulate Notify
27		|	Circulate Request
28		|	Property Notify
29		|	Selection Clear
30		|	Selection Request
31		|	Selection Notify
32		|	Colormap Notify
33		|	Client Message
34		|	Mapping Notify
35		|	Generic Event
36		|	LAST Event
*/

/*
0L			|		NoEventMask
(1L<<0)		|		KeyPressMask
(1L<<1)		|		KeyReleaseMask
(1L<<2)		|		ButtonPressMask
(1L<<3)		|		ButtonReleaseMask
(1L<<4)		|		EnterWindowMask
(1L<<5)		|		LeaveWindowMask
(1L<<6)		|		PointerMotionMask
(1L<<7)		|		PointerMotionHintMask
(1L<<8)		|		Button1MotionMask
(1L<<9)		|		Button2MotionMask
(1L<<10)	|		Button3MotionMask
(1L<<11)	|		Button4MotionMask
(1L<<12)	|		Button5MotionMask
(1L<<13)	|		ButtonMotionMask
(1L<<14)	|		KeymapStateMask
(1L<<15)	|		ExposureMask
(1L<<16)	|		VisibilityChangeMask
(1L<<17)	|		StructureNotifyMask
(1L<<18)	|		ResizeRedirectMask
(1L<<19)	|		SubstructureNotifyMask
(1L<<20)	|		SubstructureRedirectMask
(1L<<21)	|		FocusChangeMask
(1L<<22)	|		PropertyChangeMask
(1L<<23)	|		ColormapChangeMask
(1L<<24)	|		OwnerGrabButtonMask
*/

#endif //RT_KEYS_H
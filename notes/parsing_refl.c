/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_refl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:11:11 by ljohnson          #+#    #+#             */
/*   Updated: 2022/05/26 14:39:33 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// to read with errors_list.md for error numbers

if ac != 2
	return Error arg count : Usage
Parsing
{
	Check file and filename
	{
		if av[1] is a directory | open(O_RDWR)
			return Error invalid Is a directory
		if av[1] does not exist | open(O_RDWR)
			return Error invalid file Does not exist
		if av[1] does not have any . in filename | ft_int_strchr
			return error 3
		if av[1] does not have .rt at the end of filename | ft_strlen -3 ?
			return error 2
	} //Check file and filename
	Check content
	{
		Get full content of file | get_next_line
		if (!content[a])
			return error 1
		if content[a] != charset("ACLsplcy0123456789., \n-+") | ft_ischarset
			return error 4 10
		Split with space to check things | ft_split
		count things
		{
			if A count < 1 | ft_strncmp(A)
				return error 6
			if A count > 1
				return error 83
			if C count < 1 | ft_strncmp(C)
				return error 7
			if C count > 1
				return error 84
			if L count < 1 | ft_strncmp(L)
				return error 8
			if L count > 1
				return error 85
			if sp/pl/cy count < 1 | ft_strncmp (sp | pl | cy)
				return error 9
		} // count things
		find A
		{
			next two values should be Ratio and RGB
			{
				first one should be Ratio, between 0.0 to 1.0 included
				{
					if does not exist
						return error 11
					if not charset ("1234567890.+-")
						return error 12
					if not in range [0.0/1.0]
						return error 13
					give value to "ratio" of struct
				} // first one should be Ratio, between 0.0 and 1.0
				second one should be RGB, three values between 0 to 255 included
				{
					if does not exist
						return error 14
					split with ,
					{
						if split numbers < 3
							return error 17
						if one value is not charset ("1234567890")
							return error 15
						if one value is not in range [0/255]
							return error 16
						give values to "rgb" of struct
					} // split with ,
				} // second one should be RGB, three values between 0 and 255 included
			} // next two values should be Ratio and RGB
			next value should be a "\n" or NULL
			if not
				return error 86
		} // find A
		A and its values = free + ft_strdup whitespace
		find C
		{
			next three values should be xyz coordinates, xyz orientation and FOV
			{
				first one should be xyz coordinates p_xyz, three values
				{
					if does not exist
						return error 18
					split with ,
					{
						if split numbers < 3
							return error 21
						if one value is not charset ("1234567890-+.")
							return error 19
						if one value is int max+ or int min-
							return error 20
						give value to "p_xyz" of struct
					} // split with ,
				} // first one should be xyz coordinates p_xyz, three values
				second one should be xyz orientation o_xyz, three values between -1 to 1 included
				{
					if does not exist
						return error 22
					split with ,
					{
						if split numbers < 3
							return error 25
						if one value is not charset ("1234567890-+.")
							return error 23
						if one value is not in range [-1/1]
							return error 24
						give value to "o_xyz" of struct
					} // split with ,
				} // second one should be xyz orientation o_xyz, three values between -1 and 1 included
				third one should be FOV, between 0 to 180
				{
					if does not exist
						return error 26
					if is not charset("1234567890")
						return error 27
					if is not in range [0/180]
						return error 28
					give value to "fov" of struct
				} // third one should be FOV, between 0 to 180
			} // next three values should be xyz coordinates, xyz orientation and FOV
			next value should be a "\n" or NULL
			if not
				return error 86
		} // find C
		C and its values = free + ft_strdup whitespace
		find L
		{
			next two values should be xyz coord and Ratio
			{
				first one should be xyz coordinates p_xyz, three values
				{
					if does not exist
						return error 29
					split with ,
					{
						if split number < 3
							return error 32
						if one value is not charset ("1234567890-+.")
							return error 30
						if one value is float max+ or float min- | lib maths isNaN etc
							return error 31
						give value to "p_xyz" of struct
					} // split with ,
				}
				second one should be Ratio, between 0.0 to 1.0
				{
					if does not exist
						return error 33
					if is not charset ("1234567890.")
						return error 34
					if is not in range [0.0/1.0]
						return error 35
					give value to "ratio" of struct
				} // second one should be Ratio, between 0.0 to 1.0
			} // next two values should be xyz coord and Ratio
			next value should be a "\n" or NULL
			if not
				return error 86
		} // find L
		L and its values = free + ft_strdup whitespace
		end of basic struct init
		find object
		{
			if sp
			{
				create object link
				give ID value
				next three values should be xyz coords, diameter and RGB
				{
					first one should be xyz coordinates p_xyz, three values
					{
						if does not exist
							return error 36
						split with ,
						{
							if split number < 3
								return error 39
							if one value is not charset ("1234567890-+.")
								return error 37
							if one value is float max+ or float min-
								return error 38
							give value to "p_xyz" of struct
						} // split with ,
					} // first one should be xyz coordinates p_xyz, three values
					second one should be diameter
					{
						if does not exist
							return error 40
						if is not charset ("1234567890.")
							return error 41
						if is float max+ or float min-
							return error 42
						give value to "diameter" of struct
					} // second one should be diameter
					third value should be RGB, three values between 0 to 255
					{
						if does not exist
							return error 43
						split with ,
						{
							if split number < 3
								return error 46
							if one value is not charset ("1234567890")
								return error 44
							if one value is not in range[0/255]
								return error 45
							give value to "RGB" of struct
						} // split with ,
					} // third value should be RGB, three values between 0 to 255
				} // next three values should be xyz coords p+xyz, diameter and RGB
				next value should be a "\n" or NULL
				if not
					return error 86
			} // if sp
			if pl
			{
				create object link
				give ID value
				next three values should be xyz coords, xyz vector and RGB
				{
					first one should be xyz coordinates p_xyz, three values
					{
						if does not exist
							return error 47
						split with ,
						{
							if split number < 3
								return error 50
							if one value is not charset ("1234567890-+.")
								return error 48
							if one value is float max+ or float min-
								return error 49
							give alue to "p_xyz" of struct
						} // split with ,
					}
				} // next three valus shoud be xyz coords, xyz vector and RGB
			} // if pl
		}
	}
}
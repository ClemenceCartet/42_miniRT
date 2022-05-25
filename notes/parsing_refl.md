à lire avec errors_list.md pour les numéros d'erreur

if ac != 2
	return -> Error arg count : Usage
Parsing
{
	Check file and filename
	{
		if av[1] is a directory
			return -> Error invalid -> Is a directory
		if av[1] does not exist
			return -> Error invalid file -> Does not exist
		if av[1] does not have any . in filename
			return -> errors 3
		if av[1] does not have .rt at the end of filename
			return -> errors 2
	}
	Check content
	{
		Get full content of file
		{
			if (!content[a])
				return -> errors 1
			if content[a] != charset("ACLsplcy0123456789., \n-+")
				return -> errors 4 10
			split with space to check things
			{
				count things
				{
					if A count < 1
						return -> errors 6
					if A count > 1
						return -> errors 83
					if C count < 1
						return -> errors 7
					if C count > 1
						return -> errors 84
					if L count < 1
						return -> errors 8
					if L count > 1
						return -> errors 85
					if sp/pl/cy count < 1
						return -> errors 9
				}
				if ok
				{
					find A
					{
						next two values should be Ratio and RGB
						{
							first one should be Ratio, between 0.0 and 0.1
							{
								if not charset ("1234567890.+-")
									return -> errors 12 13
								if does not exist
									return -> errors 11
							}
							second one should be RGB, three values between 0 and 255 included
							{
								split with ,
								{
									if split numbers < 3
										return -> errors 17
								}
							}
						}
					}
					find C
						next three values should be xyz coordinates, xyz orientation and FOV
						if not
							return ->
					find L
						next two values should be xyz coord and Ratio
				}
			}
		}
	}
}
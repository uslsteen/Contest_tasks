#include "voc.h"

int main()
{
	char name_in1_file[MAX_NAME] = { {0} };
	char name_in2_file[MAX_NAME] = { {0} };
	char name_out_file[MAX_NAME] = { {0} };


	Input("**	Input name of file with text(for example, 'vc1.txt'):	**\n", "%s", name_in1_file);
	

	Input("**	Input name of file with words(for example 'vc2.txt'):	**\n", "%s", name_in2_file);

	Input("**	Input name of file for outputting result(for example, 'out1.txt'):	**\n", "%s", name_out_file);
	
	printf("**	Hello! Welcome to finder of words in the text!	**\n");

	Start_Working(name_in1_file, name_in2_file, name_out_file);


	// If you do not want to input a name of files every time, put a comment on the code above and remove the comment from the line below.

	//Start_Working("vc1.txt", "vc2.txt", "out.txt");

	printf("**	Program succesfully done!	**\n");

	return 0;
}
 

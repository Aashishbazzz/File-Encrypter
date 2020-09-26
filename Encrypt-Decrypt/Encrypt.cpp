#include<conio.h>
#include<fstream>
#include<iostream>

using namespace std;

class encrytp
{
	public:
		
	void write_file(void)
	{
		int log;
		log=login();
	}
		
	private:
		
		int login(void)
		{
			
			string filename, username, password;
			char ch;
			int key, i, check, no_of_try, flag;
			
			cout<<"Enter the file name ";
			cin>>filename;
			filename=filename+".txt";
			
			no_of_try=0;
			
			try_again_username:
			
			cout<<"Enter username "<<endl;
			cin>>username;
			cout<<"Enter the key "<<endl;
			cin>>key;
			
			for(i=0;i<username.length();i++)
			{
				check=user_pass_check(filename, key, i, username[i]);
				if(check==-1)
				{
					cout<<"!!!! Incorrect username !!!!";
					if(no_of_try==3)
					{
						cout<<"!!!! Entered wrong usename/password multiple times ";
						goto end;
					}
					cout<<"Do you want to try again y/n ? ";
					cin>>ch;
					if(ch=='y')
					{
						no_of_try=no_of_try+1;
						goto try_again_username;
					}
				}
				if(i==username.length()-1)
				{
					flag=1;
				}
			}
			
			try_again_password:
			
			cout<<"Enter password "<<endl;
			cin>>password;
			
			for(i=0;i<password.length();i++)
			{
				check=user_pass_check(filename, key, i, password[i]);
				if(check==-1)
				{
					cout<<"!!!! Incorrect password !!!!";
					if(no_of_try==3)
					{
						cout<<"!!!! Entered wrong usename/password multiple times ";
						goto end;
					}
					cout<<"Do you want to try again y/n ? ";
					cin>>ch;
					if(ch=='y')
					{
						no_of_try=no_of_try+1;
						goto try_again_password;
					}
				}
				if(i==password.length()-1)
				{
					flag=1;
				}
			}
			
			if(flag==1)
			{
				cout<<"Do you want to write into the file y/n ? ";
				cin>>ch;
				if(ch=='y')
				{
					file_encrypt(filename);
				}
				return 1;
				
			}
			
			else 
			{
				
				return -1;
			}
			
			end:
				cout<<"!!!! Login failed\n FILE DELETED FOR SECURITY REASONS ";
				return -1;
				
			
		}
		
		
		
		int user_pass_check(string filename, int key, int i, char ch)
		{
			int num, position, value_at_key_i;
			
			ifstream fin;
			fin.open(filename);
			
			num=ch;
			
			position=(3*k*k+2*k+k)/20+i;
			
			fin.seekg(position);
			fin>>value_at_key_i;
			
			if(value_at_key_i==num)
			{
				return 1;
			}
			
			return -1;
		}
		
		void file_encrypt(string filename)
		{
			int i, num;
			char ch;
			ofstream fout;
			fout.open(filename);
			
			fout.getline(line,100);
			
			ch='y'
			
			while(ch=='y')
			{
				cout<<"Enter line "<<endl;
				cin>>line;
				
				for(i=0;i<line.length();i++)
				{
					character=line[i];
					num=character;
					num=(num*7+num*2)/50;
					fout>>num;
				}
				
				cout<<"Want to enter more lines ";
				cin>>ch;
			}
		}
		
		
};



int main()
{
	encrypt file;
	file.write_file();
	return 0;
}

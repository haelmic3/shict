/* shict runtime compiler */
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<string>
int main(int argc,char*argv[])
{
	std::string proc = "::  ::";
	int i = 0;
	std::cout<<proc<<argv[i];
	while(++i < argc)std::cout<<" "<<argv[i];
	std::cout<<"\n"<<proc<<std::endl;
	i = 1;
	while(i<argc&&argv[i][0]=='-')
	{
		//deal with '-' operators
		++i;
	}
	if(i<argc)
	{
		uint64_t heap[0200000]
			,*ptr=heap
			,*endptr=ptr+0200000
			,*highptr=ptr
			, a=0
			, b=0
			, c=0
			, d=0
			, e=0
			, f=0
			, ac=0
			, pc=~0
			, pt=0
			;
		char x,w;
		std::string text,stack;
		{
		std::ifstream v;
		v.open(argv[i]);
		while(v.get(w))text+=w;
		v.close();
		}
		while(ptr<endptr)*(ptr++) = 0;
		ptr = heap;
		while(++pc<text.size())switch(w=text[pc])
		{
			case'+':if(stack.size())++ac;else++*ptr;break;
			case'-':if(stack.size())--ac;else--*ptr;break;
			case'>':++ptr;if(ptr>highptr)highptr=ptr;
				if(ptr>endptr)
				{
					std::cout<<proc
						<<"Operator '>' Presented"
						<<" undefined behavior."
						<<std::endl;
					/*
					std::cout<<proc<<"HEAP:"<<std::endl
					<<proc;
					ptr=heap;
					while(ptr<=highptr)
						std::cout<<*(ptr++)<<" ";
					*/
					std::cout<<std::endl<<proc<<"REG:"
						<<std::endl<<proc<<"pc=  "<<pc
						<<std::endl<<proc<<"a="
						<<std::setw(5)<<a<<"  '"
						<<(char)a<<"'"
						<<std::endl<<proc<<"b="
						<<std::setw(5)<<b<<"  '"
						<<(char)b<<"'"
						<<std::endl<<proc<<"c="
						<<std::setw(5)<<c<<"  '"
						<<(char)c<<"'"
						<<std::endl<<proc<<"d="
						<<std::setw(5)<<d<<"  '"
						<<(char)d<<"'"
						<<std::endl<<proc<<"e="
						<<std::setw(5)<<e<<"  '"
						<<(char)e<<"'"
						<<std::endl<<proc<<"f="
						<<std::setw(5)<<f<<"  '"
						<<(char)f<<"'"
						<<std::endl<<proc<<"ac="
						<<std::setw(4)<<ac<<"  '"
						<<(char)ac<<"'"
						<<std::endl;
						return 1;
				}break;
			case'<':--ptr;if(ptr<heap)
				{
					std::cout<<proc<<"Error '<' Presented"
						<<" undefined behavior."
						<<std::endl;
					/*
					std::cout<<proc<<"HEAP:"<<std::endl
					<<proc;
					ptr=heap;
					while(ptr<=highptr)
						std::cout<<*(ptr++)<<" ";
					*/
					std::cout<<std::endl<<proc<<"REG:"
						<<std::endl<<proc<<"pc=  "<<pc
						<<std::endl<<proc<<"a="
						<<std::setw(5)<<a<<"  '"
						<<(char)a<<"'"
						<<std::endl<<proc<<"b="
						<<std::setw(5)<<b<<"  '"
						<<(char)b<<"'"
						<<std::endl<<proc<<"c="
						<<std::setw(5)<<c<<"  '"
						<<(char)c<<"'"
						<<std::endl<<proc<<"d="
						<<std::setw(5)<<d<<"  '"
						<<(char)d<<"'"
						<<std::endl<<proc<<"e="
						<<std::setw(5)<<e<<"  '"
						<<(char)e<<"'"
						<<std::endl<<proc<<"f="
						<<std::setw(5)<<f<<"  '"
						<<(char)f<<"'"
						<<std::endl<<proc<<"ac="
						<<std::setw(4)<<ac<<"  '"
						<<(char)ac<<"'"
						<<std::endl;
						return 1;
				}break;
			case'.':if(stack.size())putc(ac,stdout);else putc(*ptr,stdout);break;
			case',':*ptr=getc(stdin);break;
			case':':if(stack.size())pc+=ac;else pc+=*ptr;break;
			case'=':if(stack.size())ac=*ptr;else*ptr=heap[*ptr];break;
			case'[':if(!*ptr)
				{
					while(++pc<text.size())
					if((x=text[pc])=='[')pt++;
					else if(x==']')
					{
						if(pt)--pt;
						else break;
					}
				}
				break;
			case']':while(pc-->0)
					if((x=text[pc])==']')pt++;
					else if(x=='[')
					{
						if(pt)--pt;
						else break;
					}
				break;
			case'a':if(stack.size())ac+=a;else ac=a;
				stack.push_back('a');break;
			case'b':if(stack.size())ac+=b;else ac=b;
				stack.push_back('b');break;
			case'c':if(stack.size())ac+=c;else ac=c;
				stack.push_back('c');break;
			case'd':if(stack.size())ac+=d;else ac=d;
				stack.push_back('d');break;
			case'e':if(stack.size())ac+=e;else ac=e;
				stack.push_back('e');break;
			case'f':if(stack.size())ac+=f;else ac=f;
				stack.push_back('f');break;
			case';':if(stack.size())
				{
					switch(stack.back())
					{
					case'a':a=ac;break;
					case'b':b=ac;break;
					case'c':c=ac;break;
					case'd':d=ac;break;
					case'e':e=ac;break;
					case'f':f=ac;break;
					}
				}
				stack.pop_back();
				if(!stack.size())*ptr=ac;
				break;
			case'0':ac=0;break;
			case'1':ac=1;break;
			case 0x00:
			case 0x01:
			case 0x02:
			case 0x03:
			case 0x04:
			case 0x05:
			case 0x06:
			case 0x07:
			case 0x08:
			case 0x09:
			case 0x0a:
			case 0x0b:
			case 0x0c:
			case 0x0d:
			case 0x0e:
			case 0x0f:
			case 0x10:
			case 0x11:
			case 0x12:
			case 0x13:
			case 0x14:
			case 0x15:
			case 0x16:
			case 0x17:
			case 0x18:
			case 0x19:
			case 0x1a:
			case 0x1b:
			case 0x1c:
			case 0x1d:
			case 0x1e:
			case 0x1f:
			case 0x20:
				break;
			default:putc(w,stderr);std::cout<<"|";break;
		}
		ptr = heap;
		std::cout<<proc<<std::endl;
		std::cout<<proc<<"HEAP:"<<std::endl<<proc;
		while(ptr<=highptr)std::cout<<*(ptr++)<<" ";
		std::cout<<std::endl<<proc<<"REG:"
			<<std::endl<<proc<<"a="<<std::setw(5)<<a<<"  '"<<(char)a<<"'"
			<<std::endl<<proc<<"b="<<std::setw(5)<<b<<"  '"<<(char)b<<"'"
			<<std::endl<<proc<<"c="<<std::setw(5)<<c<<"  '"<<(char)c<<"'"
			<<std::endl<<proc<<"d="<<std::setw(5)<<d<<"  '"<<(char)d<<"'"
			<<std::endl<<proc<<"e="<<std::setw(5)<<e<<"  '"<<(char)e<<"'"
			<<std::endl<<proc<<"f="<<std::setw(5)<<f<<"  '"<<(char)f<<"'"
			<<std::endl<<proc<<"ac="<<std::setw(4)<<ac<<"  '"<<(char)ac<<"'"
			<<std::endl;
	}
	else
	{
		std::cout<<proc<<"No file specified."<<std::endl;
	}
	return 0;
}

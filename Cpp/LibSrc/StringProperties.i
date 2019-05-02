
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt



bool JB_Str_IsASCII(JB_String* self) {
	return IsAsciiSub_( self->Addr, self->Length );
}

int JB_Str_LengthUTF8(JB_String* self) {
	return u8Count_( self->Addr, self->Length );
}


#include "functions.h"
#include "libgraphqlparser/AstNode.h"
#include "libgraphqlparser/GraphQLParser.h"
#include "libgraphqlparser/c/GraphQLAstToJSON.h"


using v8::Local;


NAN_METHOD(parseString) {
	const char *error;

	if (info.Length() <= 0 || !info[0]->IsString()) {
		Nan::ThrowTypeError("`parseString` should have a string as argument.");
		return;
	}

	Local<v8::String> source = info[0].As<v8::String>();

	Nan::Utf8String val(source);
    char *in = *val;

 	auto AST = facebook::graphql::parseString(in, &error);

  	if (!AST) {
    	Nan::ThrowTypeError(error);
    	free((void *)error);
    	return;
  	}

  	const char *result = graphql_ast_to_json((const struct GraphQLAstNode *)AST.get());
    info.GetReturnValue().Set(Nan::New(result).ToLocalChecked());
}

NAN_METHOD(parseFile) {
	const char *error;
	FILE * in;

	if (info.Length() <= 0 || !info[0]->IsString()) {
		Nan::ThrowTypeError("`parseString` should have a string as argument.");
		return;
	}

	Local<v8::String> source = info[0].As<v8::String>();

	Nan::Utf8String val(source);
    char *path = *val;

    in = fopen(path, "r");

  	auto AST = facebook::graphql::parseFile(in, &error);

    fclose(in);

  	if (!AST) {
    	Nan::ThrowTypeError(error);
    	free((void *)error);
    	return;
  	}

  	const char *result = graphql_ast_to_json((const struct GraphQLAstNode *)AST.get());
    info.GetReturnValue().Set(Nan::New(result).ToLocalChecked());
}

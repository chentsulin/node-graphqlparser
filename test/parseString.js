var GraphQLParser = require('../');
var assert = require('assert');


describe('#parseString', function() {
  it('should throw when no any arguments', function() {
    try {
      GraphQLParser.parseString();
    } catch (e) {
      assert.equal(e.message, '`parseString` should have a string as argument.');
    }
  });

  it('should throw when no argument is not a string', function() {
    try {
      GraphQLParser.parseString(1);
    } catch (e) {
      assert.equal(e.message, '`parseString` should have a string as argument.');
    }

    try {
      GraphQLParser.parseString(true);
    } catch (e) {
      assert.equal(e.message, '`parseString` should have a string as argument.');
    }

    try {
      GraphQLParser.parseString({});
    } catch (e) {
      assert.equal(e.message, '`parseString` should have a string as argument.');
    }

     try {
      GraphQLParser.parseString([]);
    } catch (e) {
      assert.equal(e.message, '`parseString` should have a string as argument.');
    }
  });

  it('should throw when string invalid', function() {
    try {
      GraphQLParser.parseString('a invalid string');
    } catch (e) {
      assert.equal(e.message, '`parseString` should have a string as argument.');
    }
  });

  it('should works', function() {

    var result = GraphQLParser.parseString('{}');
    assert.deepEqual(result, {});
  });
});

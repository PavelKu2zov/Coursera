#pragma once

#include <date.h>
#include <memory>

enum class Comparison
{
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual,
};

enum class LogicalOperation
{
    And,
    Or,
};

class Node
{
public:
    virtual bool Evaluate(const Date& date, const string& event) = 0;
};

class EmptyNode : public Node
{
public:
    bool Evaluate(const Date& date, const string& event)
    {
        return false;
    }
};


class DateComparisonNode : public Node
{
public:

    DateComparisonNode(const Comparison& cmp, const Date& date);

    bool Evaluate(const Date& date, const string& event) override;

private:
    const Comparison cmp;
    const Date dateCmp;
};

class EventComparisonNode : public Node
{
public:

    EventComparisonNode(const Comparison& cmp, const string& event);

    bool Evaluate(const Date& date, const string& event) override;

private:
    const Comparison cmp;
    const string eventCmp;
};


class LogicalOperationNode : public Node{
public:
    LogicalOperationNode(const LogicalOperation& logicalOperation, const shared_ptr<Node> _lhsNode,const shared_ptr<Node> _rhsNode);

    bool Evaluate(const Date& date, const string& event) override;

private:
    const LogicalOperation logicalOperation;
    const shared_ptr<Node> lhsNode;
    const shared_ptr<Node> rhsNode;
};
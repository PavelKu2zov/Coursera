#include <node.h>

using namespace std;


DateComparisonNode::DateComparisonNode(const Comparison &cmp, const Date &date)
    : cmp(cmp),
      dateCmp(date){}

bool DateComparisonNode::Evaluate(const Date &date, const string &event) {
    bool result = false;

    switch (cmp) {
        case Comparison::Equal:
            if (date == dateCmp)
                result = true;
                break;
        case Comparison::Greater:
            if (date > dateCmp)
                result = true;
                break;
        case Comparison::GreaterOrEqual:
            if (date >= dateCmp)
                result = true;
                break;
        case Comparison::Less:
            if (date < dateCmp)
                result = true;
                break;
        case Comparison::LessOrEqual:
            if (date <= dateCmp)
                result = true;
                break;
        case Comparison::NotEqual:
            if (date != dateCmp)
                result = true;
                break;
        default:
                result = false;

    }

    return result;
}



EventComparisonNode::EventComparisonNode(const Comparison &cmp, const string &event)
        : cmp(cmp),
          eventCmp(event){}

bool EventComparisonNode::Evaluate(const Date &date, const string &event) {
    bool result = false;

    switch (cmp) {
        case Comparison::Equal:
            if (event == eventCmp)
                result = true;
            break;
        case Comparison::Greater:
            if (event > eventCmp)
                result = true;
            break;
        case Comparison::GreaterOrEqual:
            if (event >= eventCmp)
                result = true;
            break;
        case Comparison::Less:
            if (event < eventCmp)
                result = true;
            break;
        case Comparison::LessOrEqual:
            if (event <= eventCmp)
                result = true;
            break;
        case Comparison::NotEqual:
            if (event != eventCmp)
                result = true;
            break;
        default:
            result = false;

    }

    return result;
}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation& logicalOperation, const shared_ptr<Node> _lhsNode,const shared_ptr<Node> _rhsNode)
        : logicalOperation(logicalOperation),
          lhsNode(_lhsNode),
          rhsNode(_rhsNode){}

bool LogicalOperationNode::Evaluate(const Date &date, const string &event) {
    bool result = false;

    if (logicalOperation == LogicalOperation::And)
    {
        if (lhsNode->Evaluate(date,event) && rhsNode->Evaluate(date,event))
            result = true;
        else
            result = false;
    }
    else if (logicalOperation == LogicalOperation::Or)
    {
        if (lhsNode->Evaluate(date,event) || rhsNode->Evaluate(date,event))
            result = true;
        else
            result = false;
    }

    return result;
}


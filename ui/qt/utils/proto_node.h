/* proto_node.h
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef PROTO_NODE_H_
#define PROTO_NODE_H_

#include <config.h>

#include <ui/qt/utils/field_information.h>

struct VectorLabelText
{
    QString labelText;
    QVector<VectorLabelText> vecLabelText;
};

class ProtoNode
{
public:

    class ChildIterator {
    public:
        typedef struct _proto_node * NodePtr;

        ChildIterator(NodePtr n = Q_NULLPTR);

        bool hasNext();
        ChildIterator next();
        ProtoNode element();

    protected:
        NodePtr node;
    };

    explicit ProtoNode(proto_node * node = NULL);

    bool isValid() const;
    bool isChild() const;
    bool isExpanded() const;

    proto_node *protoNode() const;
    int childrenCount() const;

    QVector<VectorLabelText> allLabelText() const;
    void allLabelText(VectorLabelText &vecLabelText, ChildIterator child) const;

    int row();
    ProtoNode parentNode();

    QString labelText() const;

    ChildIterator children() const;

private:
    proto_node * node_;
    static bool isHidden(proto_node * node);
};


#endif // PROTO_NODE_H_

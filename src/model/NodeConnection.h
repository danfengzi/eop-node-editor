#pragma once

#include <QObject>

class NodePortModel;

class NodeConnection : public QObject
{
	Q_OBJECT
public:
	enum EDirection
	{
		INCOMING,
		OUTGOING
	};

	NodeConnection(NodePortModel* input, NodePortModel* output);
	~NodeConnection();

	bool composed_by(NodePortModel* first_port, NodePortModel* second_port) const;
	NodePortModel* input() const;
	NodePortModel* output() const;
	NodePortModel* other(NodePortModel* port) const;
	void remove_port(NodePortModel* port_model); // TODO not too happy about this, but hopefully prevents crash

	void set_valid(bool valid);
	bool is_valid() const;

signals:
	void connection_destroyed();

private:
	NodePortModel* m_input;
	NodePortModel* m_output;
	bool m_valid = true;
};
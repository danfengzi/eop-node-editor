#pragma once

#include <QObject>
#include <vector>

class QPointF;

class NodeGraph;
class NodeFactory;
class NodeConnection;
class NodeModel;
class NodePortModel;

class NodeGraphController : public QObject
{
	Q_OBJECT
public:
	NodeGraphController(NodeGraph& node_graph);
	~NodeGraphController() = default;

	void set_node_factory(NodeFactory* factory);
	NodeModel* add_node(const QPointF& position);
	void delete_node(NodeModel* node_model);
	void delete_connection(NodeConnection* connection);
	void clear_graph();

	void set_first_connection_port(NodePortModel* port);
	void set_second_connection_port(NodePortModel* port);
	NodeConnection* create_connection();

	void set_persisted();
	bool is_persisted() const;

	void start_load();
	void end_load();

	void notify_node_graph_changed();

signals:
	void message(const QString& message, bool status);
	void node_graph_changed();

	void node_added(NodeModel* node_model);
	void connection_created(NodeConnection* connection);

private:
	NodeGraph& m_node_graph;
	NodeFactory* m_node_factory = nullptr;
	NodePortModel* m_first_connection_port = nullptr;
	NodePortModel* m_second_connection_port = nullptr;
	bool m_persisted = true;
	bool m_loading = false;
};
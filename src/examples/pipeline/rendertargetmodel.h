#pragma once

#include <src/model/NodeModel.h>
#include <src/model/NodePortModel.h>

class RenderTarget;

class RenderTargetInputPortModel : public NodePortModel
{
public:
	RenderTargetInputPortModel(const QString& name) : m_name(name) {}
	EPortType port_type() const override { return NodePortModel::INPUT; }
	QString port_label() const override { return m_name; }

private:
	QString m_name;
};


class RenderTargetNodeModel : public NodeModel
{
public:
	RenderTargetNodeModel(RenderTarget* rendertarget);

	void create_port_models() override;
	void destroy_port_models() override;
	QString title() const override;
	uint32_t num_ports() const override;
	NodePortModel* port_model(uint32_t port_nr) override;

private:
	RenderTarget* m_target = nullptr;
	QVector<NodePortModel*> m_port_models;

};
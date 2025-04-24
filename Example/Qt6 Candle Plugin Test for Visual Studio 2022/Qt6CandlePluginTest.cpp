#include "Qt6CandlePluginTest.h"
#include <QCanBus>
#include <QCanBusDeviceInfo>

Qt6CandlePluginTest::Qt6CandlePluginTest(QWidget *parent)
    : QMainWindow(parent),
    m_tree(new QTreeWidget(this))
{
    // One column for the plugin/device name, one for a description
    m_tree->setHeaderLabels({ tr("Plugin / Device"), tr("Description") });
    setCentralWidget(m_tree);

    // 1) List all available plugin keys
    const QStringList plugins = QCanBus::instance()->plugins();
    for (const QString& pluginKey : plugins) {
        // Top‑level tree node = the plugin name
        auto* pluginItem = new QTreeWidgetItem(m_tree);
        pluginItem->setText(0, pluginKey);

        // 2) Query devices for that plugin
        QString errorString;
        const auto devInfos =
            QCanBus::instance()->availableDevices(pluginKey, &errorString);
        if (!errorString.isEmpty()) {
            // If something went wrong, show the error
            auto* err = new QTreeWidgetItem(pluginItem);
            err->setText(0, tr("Error: %1").arg(errorString));
            continue;
        }

        // 3) Add one child per device
        for (const QCanBusDeviceInfo& info : devInfos) {
            auto* devItem = new QTreeWidgetItem(pluginItem);
            devItem->setText(0, info.name());
            devItem->setText(1, info.description());
        }
    }

    // Expand everything so you can see the device lists immediately
    m_tree->expandAll();

}

Qt6CandlePluginTest::~Qt6CandlePluginTest()
{}

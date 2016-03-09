import QtQuick 2.0
import Ubuntu.Components 1.1
import ReadFileQML 1.0

/*!
    \brief MainView with Tabs element.
           First Tab has a single Label and
           second Tab has a single ToolbarAction.
*/

MainView {
    // objectName for functional testing purposes (autopilot-qt5)
    objectName: "mainView"

    // Note! applicationName needs to match the "name" field of the click manifest
    applicationName: "readfileqml.liu-xiao-guo"

    /*
     This property enables the application to change orientation
     when the device is rotated. The default is false.
    */
    //automaticOrientation: true

    // Removes the old toolbar and enables new features of the new header.
    useDeprecatedToolbar: false

    width: units.gu(60)
    height: units.gu(76)

    Page {
        title: i18n.tr("Read File QML")

        Text {
            id: myText
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: button.top

            wrapMode: Text.Wrap
        }

        Button {
            id: button
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom:parent.bottom
            height: units.gu(5)

            text: "Reload file"

            onClicked: {
                console.log("button is clicked!");
                //reload the file
                myText.text =  myFile.read();
            }
        }

        FileIO {
            id: myFile
            source: "good.txt"
            onError: console.log(msg)
        }

        Component.onCompleted: {
            console.log( "WRITE: "+ myFile.write("this is really cool!"));
            console.log("source: " + myFile.source );
            myText.text =  myFile.read();
        }
    }
}


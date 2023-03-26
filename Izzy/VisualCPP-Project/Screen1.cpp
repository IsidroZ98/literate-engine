#include <wx/wx.h>
#include <wx/timer.h>
#include <wx/stattext.h>

class MyFrame : public wxFrame
{
public:
    MyFrame() : wxFrame(NULL, wxID_ANY, "Timer Demo")
    {
        // Create a timer that fires every second
        m_timer = new wxTimer(this, wxID_ANY);
        m_timer->Start(1000);

        // Create a countdown label
        m_countdownLabel = new wxStaticText(this, wxID_ANY, "Countdown: 10");

        // Create a sizer to arrange the widgets
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        sizer->Add(m_countdownLabel, wxSizerFlags().Border(wxALL, 20));

        // Set the sizer for the frame
        SetSizer(sizer);

        // Connect the timer event to our handler
        Bind(wxEVT_TIMER, &MyFrame::OnTimer, this);
    }

private:
    wxTimer* m_timer;
    wxStaticText* m_countdownLabel;
    int m_countdown = 10;

    void OnTimer(wxTimerEvent& event)
    {
        // Decrement the countdown and update the label
        m_countdown--;
        m_countdownLabel->SetLabel(wxString::Format("Countdown: %d", m_countdown));

        // If the countdown reaches zero, stop the timer
        if (m_countdown == 0)
        {
            m_timer->Stop();
            wxMessageBox("Countdown complete!");
        }
    }
};

class MyApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        MyFrame* frame = new MyFrame();
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);


//Comment2